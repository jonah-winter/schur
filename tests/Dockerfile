FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /schur-lib

COPY . .

RUN cmake -S . -B dockerbuild  \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_COMPILER=g++

RUN cmake --build dockerbuild

CMD ["./dockerbuild/tests/mat"]
