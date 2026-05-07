FROM ubuntu:22.04
RUN apt-get update && apt-get install -y gcc cmake make
WORKDIR /app
COPY . .
RUN cmake -S . -B build && cmake --build build
CMD ["./build/clion_BS2026"]