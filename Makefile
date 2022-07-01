.PHONY: executables makedirs
all: makedirs executables
build/pdjson.o: src/pdjson.cpp src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/pdjson.o src/pdjson.cpp -Isrc -Isrc
build/websocket/websocket.o: src/websocket/websocket.cpp src/websocket/websocket.h src/websocket/base64.h src/error.h src/settings.h src/commons.h src/gslist.h src/websocket/sha1.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/websocket.o src/websocket/websocket.cpp -Isrc -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gmenu.o: src/gmenu.cpp src/gmenu.h src/xmalloc.h src/ui.h src/sort.h src/commons.h src/color.h src/labels.h src/parser.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gmenu.o src/gmenu.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/facss.o: src/resources/facss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/facss.o src/resources/facss.cpp -Isrc
build/gkhash.o: src/gkhash.cpp src/gkhash.h src/gstorage.h src/error.h src/settings.h src/util.h src/persistence.h src/khash.h src/sort.h src/parser.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gkhash.o src/gkhash.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gslist.o: src/gslist.cpp src/gstorage.h src/parser.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gslist.o src/gslist.cpp -Isrc -Isrc
build/output.o: src/output.cpp src/resources/appcss.h src/util.h src/xmalloc.h src/ui.h src/color.h src/json.h src/resources/appjs.h src/labels.h src/resources/d3js.h src/resources/bootstrapcss.h src/sort.h src/output.h src/gslist.h src/websocket/websocket.h src/commons.h src/resources/tpls.h src/settings.h src/parser.h src/error.h src/gstorage.h src/resources/facss.h src/khash.h src/gkhash.h src/websocket/gwsocket.h src/resources/hoganjs.h src/resources/chartsjs.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/output.o src/output.cpp -Isrc -Isrc/websocket -Isrc -Isrc/resources -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gholder.o: src/gholder.cpp src/commons.h src/geoip1.h src/xmalloc.h src/khash.h src/gslist.h src/sort.h src/gholder.h src/gkhash.h src/util.h src/settings.h src/gstorage.h src/parser.h src/gdns.h src/error.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gholder.o src/gholder.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/khash.o: src/khash.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/khash.o src/khash.cpp -Isrc
build/gstorage.o: src/gstorage.cpp src/geoip1.h src/browsers.h src/opesys.h src/xmalloc.h src/labels.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/error.h src/parser.h src/gstorage.h src/gkhash.h src/util.h src/settings.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gstorage.o src/gstorage.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/hoganjs.o: src/resources/hoganjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/hoganjs.o src/resources/hoganjs.cpp -Isrc
build/parser.o: src/parser.cpp src/gkhash.h src/pdjson.h src/browsers.h src/xmalloc.h src/websocket/websocket.h src/commons.h src/util.h src/khash.h src/goaccess.h src/settings.h src/parser.h src/gstorage.h src/error.h src/gslist.h src/sort.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/parser.o src/parser.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdns.o: src/gdns.cpp src/gkhash.h src/xmalloc.h src/util.h src/khash.h src/goaccess.h src/settings.h src/commons.h src/color.h src/labels.h src/sort.h src/gslist.h src/ui.h src/gdns.h src/error.h src/parser.h src/gstorage.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdns.o src/gdns.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/ui.o: src/ui.cpp src/settings.h src/xmalloc.h src/goaccess.h src/khash.h src/sort.h src/gslist.h src/commons.h src/error.h src/gmenu.h src/gstorage.h src/parser.h src/gkhash.h src/util.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui.o src/ui.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/settings.o: src/settings.cpp src/error.h src/settings.h src/util.h src/parser.h src/commons.h src/gslist.h src/khash.h src/gstorage.h src/gkhash.h src/pdjson.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/settings.o src/settings.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/tpls.o: src/resources/tpls.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/tpls.o src/resources/tpls.cpp -Isrc
build/xmalloc.o: src/xmalloc.cpp src/error.h src/settings.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/xmalloc.o src/xmalloc.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/util.o: src/util.cpp src/util.h src/error.h src/settings.h src/commons.h src/gslist.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util.o src/util.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/sha1.o: src/websocket/sha1.cpp src/websocket/sha1.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/sha1.o src/websocket/sha1.cpp -Isrc -Isrc/websocket
build/browsers.o: src/browsers.cpp src/browsers.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/browsers.o src/browsers.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/opesys.o: src/opesys.cpp src/opesys.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opesys.o src/opesys.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/appjs.o: src/resources/appjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appjs.o src/resources/appjs.cpp -Isrc
build/tpl.o: src/tpl.cpp src/tpl.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/tpl.o src/tpl.cpp -Isrc -Isrc
build/resources/bootstrapcss.o: src/resources/bootstrapcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/bootstrapcss.o src/resources/bootstrapcss.cpp -Isrc
build/bin2c.o: src/bin2c.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/bin2c.o src/bin2c.cpp -Isrc -Isrc
build/resources/chartsjs.o: src/resources/chartsjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/chartsjs.o src/resources/chartsjs.cpp -Isrc
build/labels.o: src/labels.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/labels.o src/labels.cpp -Isrc
build/persistence.o: src/persistence.cpp src/persistence.h src/error.h src/settings.h src/util.h src/gkhash.h src/gstorage.h src/khash.h src/sort.h src/parser.h src/commons.h src/gslist.h src/tpl.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/persistence.o src/persistence.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdashboard.o: src/gdashboard.cpp src/gdashboard.h src/ui.h src/labels.h src/xmalloc.h src/commons.h src/util.h src/settings.h src/parser.h src/gstorage.h src/error.h src/color.h src/gslist.h src/sort.h src/khash.h src/gholder.h src/gkhash.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdashboard.o src/gdashboard.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/d3js.o: src/resources/d3js.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/d3js.o src/resources/d3js.cpp -Isrc
build/json.o: src/json.cpp src/json.h src/settings.h src/xmalloc.h src/labels.h src/color.h src/websocket/websocket.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/error.h src/parser.h src/gstorage.h src/gkhash.h src/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/json.o src/json.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/gwsocket.o: src/websocket/gwsocket.cpp src/websocket/gwsocket.h src/xmalloc.h src/json.h src/websocket/websocket.h src/commons.h src/settings.h src/goaccess.h src/parser.h src/error.h src/gslist.h src/sort.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/gwsocket.o src/websocket/gwsocket.cpp -Isrc -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/color.o: src/color.cpp src/color.h src/commons.h src/error.h src/settings.h src/util.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/color.o src/color.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/geoip1.o: src/geoip1.cpp src/commons.h src/geoip1.h src/gslist.h src/error.h src/settings.h src/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/geoip1.o src/geoip1.cpp -Isrc -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/options.o: src/options.cpp src/options.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/options.o src/options.cpp -Isrc -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/goaccess.o: src/goaccess.cpp src/persistence.h src/resources/chartsjs.h src/resources/tpls.h src/resources/bootstrapcss.h src/tpl.h src/resources/appjs.h src/opesys.h src/websocket/sha1.h src/util.h src/xmalloc.h src/settings.h src/ui.h src/gdashboard.h src/resources/d3js.h src/json.h src/websocket/gwsocket.h src/color.h src/geoip1.h src/labels.h src/options.h src/goaccess.h src/websocket/base64.h src/sort.h src/resources/appcss.h src/csv.h src/commons.h src/browsers.h src/error.h src/gdns.h src/parser.h src/resources/hoganjs.h src/gstorage.h src/khash.h src/gholder.h src/output.h src/gslist.h src/gkhash.h src/resources/facss.h src/gmenu.h src/websocket/websocket.h src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/goaccess.o src/goaccess.cpp -Isrc -Isrc/websocket -Isrc/resources -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/base64.o: src/websocket/base64.cpp src/websocket/base64.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/base64.o src/websocket/base64.cpp -Isrc -Isrc -Isrc/websocket
build/sort.o: src/sort.cpp src/error.h src/settings.h src/util.h src/sort.h src/parser.h src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/sort.o src/sort.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/appcss.o: src/resources/appcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appcss.o src/resources/appcss.cpp -Isrc
build/csv.o: src/csv.cpp src/csv.h src/labels.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/gkhash.h src/util.h src/settings.h src/parser.h src/gstorage.h src/error.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/csv.o src/csv.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/commons.o: src/commons.cpp src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/commons.o src/commons.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/error.o: src/error.cpp src/error.h src/settings.h src/labels.h src/parser.h src/gslist.h src/commons.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/error.o src/error.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/bin2c.exe: build/bin2c.o
	g++ -flto -Werror -ltcmalloc -o build/bin2c.exe build/bin2c.o -lbz2
build/goaccess.exe: build/pdjson.o build/websocket/websocket.o build/gmenu.o build/json.o build/opesys.o build/persistence.o build/ui.o build/xmalloc.o build/error.o build/settings.o build/websocket/sha1.o build/tpl.o build/websocket/gwsocket.o build/goaccess.o build/websocket/base64.o build/sort.o build/color.o build/csv.o build/output.o build/gdns.o build/util.o build/browsers.o build/gdashboard.o build/commons.o build/parser.o build/geoip1.o build/gstorage.o build/gholder.o build/gkhash.o build/options.o build/gslist.o
	g++ -flto -Werror -ltcmalloc -o build/goaccess.exe build/pdjson.o build/websocket/websocket.o build/gmenu.o build/json.o build/opesys.o build/persistence.o build/ui.o build/xmalloc.o build/error.o build/settings.o build/websocket/sha1.o build/tpl.o build/websocket/gwsocket.o build/goaccess.o build/websocket/base64.o build/sort.o build/color.o build/csv.o build/output.o build/gdns.o build/util.o build/browsers.o build/gdashboard.o build/commons.o build/parser.o build/geoip1.o build/gstorage.o build/gholder.o build/gkhash.o build/options.o build/gslist.o -lGeoIP -lncurses -ltinfo -lssl -lcrypto
executables: build/bin2c.exe build/goaccess.exe
makedirs:
	mkdir -p build/resources build/websocket build
