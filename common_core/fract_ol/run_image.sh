#!/bin/bash
#docker run --platform linux/amd64 -it --rm -v "$PWD":/app valgrind-env
docker run --platform linux/amd64 -it --rm -v "$PWD":/app -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix valgrind-env

