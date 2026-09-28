FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y cmake g++-14 libgtest-dev


WORKDIR /schur-lib

COPY . .

RUN cmake -S tests -B dockerbuild \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_COMPILER=g++-14

RUN cmake --build dockerbuild

CMD ["./dockerbuild/lib/lib_test"]
