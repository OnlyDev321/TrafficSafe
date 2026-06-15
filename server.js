const express = require("express");
const https = require("https");
const fs = require("fs");
const path = require("path");
const { SerialPort } = require("serialport");

const app = express();

// initiallize SerialPort
const sp = new SerialPort({
  path: "/dev/cu.usbmodem14011",
  baudRate: 115200,
});

// 정적 파일 제공
app.use(express.static("public"));

// SSL 인증서 설정
const options = {
  key: fs.readFileSync("key.pem"),
  cert: fs.readFileSync("cert.pem"),
};

// HTTPS 서버 생성
const server = https.createServer(options, app);

// Socket.IO 설정
const io = require("socket.io")(server, {
  cors: {
    origin: "*",
    methods: ["GET", "POST"],
  },
});

// 연결된 클라이언트 관리
let clients = new Set();

io.on("connection", (socket) => {
  clients.add(socket.id);
  console.log(`클라이언트 연결됨: ${socket.id}, 총 연결: ${clients.size}`);

  // Offer 처리
  socket.on("offer", (offer) => {
    console.log(`Offer 수신됨 (from: ${socket.id})`);

    socket.broadcast.emit("offer", offer);
  });

  // Answer 처리
  socket.on("answer", (answer) => {
    console.log(`Answer 수신됨 (from: ${socket.id})`);
    socket.broadcast.emit("answer", answer);
  });

  // ICE candidate 처리
  socket.on("ice-candidate", (candidate) => {
    console.log(`ICE candidate 수신됨 (from: ${socket.id})`);
    socket.broadcast.emit("ice-candidate", candidate);
  });

  // 연결 해제 처리
  socket.on("disconnect", () => {
    clients.delete(socket.id);
    console.log(
      `클라이언트 연결 해제: ${socket.id}, 남은 연결: ${clients.size}`
    );
  });
});

sp.open((err) => {
  if (err) {
    console.error("Error opening serial port:", err.message);
    return;
  }
  console.log("Serial port has been opened");
});

sp.on("error", (err) => {
  console.error("Serial port error:", err.message);
});

// receive data from serial port and send it to the client
sp.on("data", (data) => {
  // console.log(data.toString());
  io.emit("log", data.toString());
});

// 서버 시작
const PORT = 3000;
server.listen(PORT, () => {
  console.log(`HTTPS 서버가 포트 ${PORT}에서 실행중입니다.`);
  console.log(`https://localhost:${PORT} 에서 접속 가능합니다.`);
});

// 에러 처리
server.on("error", (err) => {
  console.error("서버 에러:", err);
});
