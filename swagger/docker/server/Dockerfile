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
RUN mkdir -p /opt/build/RPX100/swagger/RPX100

WORKDIR /opt/build/RPX100/swagger/RPX100
ENTRYPOINT [ "http-server", "-p 8081", "--cors"]
