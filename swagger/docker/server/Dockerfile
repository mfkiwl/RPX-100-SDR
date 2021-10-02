FROM node:alpine as base

# Install base packages
RUN apk update && apk add sudo

RUN npm install -g http-server

# Give node user sudo rights and default to it
RUN addgroup node wheel
RUN echo '%wheel ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER node

RUN sudo mkdir /opt/build \
    && sudo chown node:node /opt/build
WORKDIR /opt/build

FROM base as codegen_server
RUN mkdir -p /opt/build/rpx-100/swagger/rpx-100

WORKDIR /opt/build/rpx-100/swagger/rpx-100
ENTRYPOINT [ "http-server", "-p 8081", "--cors"]
