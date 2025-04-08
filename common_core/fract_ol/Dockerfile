# Use x86_64 Ubuntu base image
FROM ubuntu:22.04

# Install necessary tools
RUN apt-get update && apt-get install -y \
    build-essential \
    valgrind \
    gcc \
    gdb \
    make \
    nano \
    vim \
    libbsd-dev \
    libx11-dev \
    libxext-dev \
    libxft-dev \
    libxrender-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy your C files
COPY . .

# Default command
CMD ["/bin/bash"]
