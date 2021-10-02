#!/bin/sh

get_abs_dir() {
  # $1 : relative filename
  echo "$(cd "$(dirname "$1")" && pwd)"
}

RPX100_RESOURCES="$(get_abs_dir "$0")/../Resources"
exec "$RPX100_RESOURCES/RPX100"

