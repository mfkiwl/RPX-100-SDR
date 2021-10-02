#!/bin/sh

get_abs_dir() {
  # $1 : relative filename
  echo "$(cd "$(dirname "$1")" && pwd)"
}

rpx-100_RESOURCES="$(get_abs_dir "$0")/../Resources"
exec "$rpx-100_RESOURCES/rpx-100"

