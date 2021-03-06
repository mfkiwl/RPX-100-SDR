#!/bin/sh

CODEGEN=/opt/install/swagger/swagger-codegen
RPX100_SRC=/opt/build/RPX100

${CODEGEN} generate -i api/swagger/swagger.yaml -l qt5cpp -c qt5cpp-config.json -o code/qt5
${CODEGEN} generate -i api/swagger/swagger.yaml -l html2 -c html2-config.json -o code/html2
cp -v code/html2/index.html ${RPX100_SRC}/sdrbase/resources/webapi/doc/html2
cp -av api/swagger/ ${RPX100_SRC}/sdrbase/resources/webapi/doc
find ${RPX100_SRC}/sdrbase/resources/webapi/doc/swagger -name \*.yaml -exec sed -i 's/http:\/\/swgserver:8081\/api\/swagger\/include/\/doc\/swagger\/include/g' {} \;
