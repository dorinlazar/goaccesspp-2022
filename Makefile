.PHONY: executables makedirs
all: makedirs executables
build/pdjson.o: src/pdjson.cpp src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/pdjson.o src/pdjson.cpp -Isrc -Isrc
build/gmenu.o: src/gmenu.cpp src/gmenu.h src/xmalloc.h src/ui.h src/sort.h src/commons.h src/color.h src/labels.h src/parser.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gmenu.o src/gmenu.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gkhash.o: src/gkhash.cpp src/gkhash.h src/gstorage.h src/error.h src/settings.h src/util.h src/persistence.h src/khash.h src/sort.h src/parser.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gkhash.o src/gkhash.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/sort.o: src/sort.cpp src/error.h src/settings.h src/util.h src/sort.h src/parser.h src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/sort.o src/sort.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/output.o: src/output.cpp src/appcss.h src/websocket/gwsocket.h src/bootstrapcss.h src/gkhash.h src/khash.h src/tpls.h src/xmalloc.h src/facss.h src/util.h src/ui.h src/appjs.h src/hoganjs.h src/chartsjs.h src/d3js.h src/sort.h src/output.h src/gslist.h src/json.h src/websocket/websocket.h src/commons.h src/settings.h src/gstorage.h src/parser.h src/error.h src/labels.h src/color.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/output.o src/output.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/labels.o: src/labels.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/labels.o src/labels.cpp -Isrc
build/websocket/sha1.o: src/websocket/sha1.cpp src/websocket/sha1.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/sha1.o src/websocket/sha1.cpp -Isrc -Isrc/websocket
build/tpl.o: src/tpl.cpp src/tpl.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/tpl.o src/tpl.cpp -Isrc -Isrc
build/websocket/base64.o: src/websocket/base64.cpp src/websocket/base64.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/base64.o src/websocket/base64.cpp -Isrc -Isrc -Isrc/websocket
build/goaccess.o: src/goaccess.cpp src/d3js.h src/chartsjs.h src/appjs.h src/tpls.h src/opesys.h src/bootstrapcss.h src/xmalloc.h src/json.h src/geoip1.h src/websocket/gwsocket.h src/error.h src/color.h src/facss.h src/ui.h src/gdashboard.h src/csv.h src/gholder.h src/options.h src/settings.h src/websocket/websocket.h src/persistence.h src/commons.h src/browsers.h src/gdns.h src/parser.h src/gstorage.h src/hoganjs.h src/khash.h src/appcss.h src/gslist.h src/util.h src/goaccess.h src/websocket/base64.h src/tpl.h src/websocket/sha1.h src/labels.h src/output.h src/sort.h src/gkhash.h src/gmenu.h src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/goaccess.o src/goaccess.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/util.o: src/util.cpp src/util.h src/error.h src/settings.h src/commons.h src/gslist.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util.o src/util.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gslist.o: src/gslist.cpp src/gstorage.h src/parser.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gslist.o src/gslist.cpp -Isrc -Isrc
build/appcss.o: src/appcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/appcss.o src/appcss.cpp -Isrc
build/geoip1.o: src/geoip1.cpp src/commons.h src/geoip1.h src/gslist.h src/error.h src/settings.h src/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/geoip1.o src/geoip1.cpp -Isrc -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/color.o: src/color.cpp src/color.h src/commons.h src/error.h src/settings.h src/util.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/color.o src/color.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/error.o: src/error.cpp src/error.h src/settings.h src/labels.h src/parser.h src/gslist.h src/commons.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/error.o src/error.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/gwsocket.o: src/websocket/gwsocket.cpp src/websocket/gwsocket.h src/xmalloc.h src/json.h src/websocket/websocket.h src/commons.h src/settings.h src/goaccess.h src/parser.h src/error.h src/gslist.h src/sort.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/gwsocket.o src/websocket/gwsocket.cpp -Isrc -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/json.o: src/json.cpp src/json.h src/settings.h src/xmalloc.h src/labels.h src/color.h src/websocket/websocket.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/error.h src/parser.h src/gstorage.h src/gkhash.h src/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/json.o src/json.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/opesys.o: src/opesys.cpp src/opesys.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opesys.o src/opesys.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/xmalloc.o: src/xmalloc.cpp src/error.h src/settings.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/xmalloc.o src/xmalloc.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/bootstrapcss.o: src/bootstrapcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/bootstrapcss.o src/bootstrapcss.cpp -Isrc
build/tpls.o: src/tpls.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/tpls.o src/tpls.cpp -Isrc
build/settings.o: src/settings.cpp src/error.h src/settings.h src/util.h src/parser.h src/commons.h src/gslist.h src/khash.h src/gstorage.h src/gkhash.h src/pdjson.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/settings.o src/settings.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/chartsjs.o: src/chartsjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/chartsjs.o src/chartsjs.cpp -Isrc
build/d3js.o: src/d3js.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/d3js.o src/d3js.cpp -Isrc
build/appjs.o: src/appjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/appjs.o src/appjs.cpp -Isrc
build/bin2c.o: src/bin2c.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/bin2c.o src/bin2c.cpp -Isrc -Isrc
build/ui.o: src/ui.cpp src/settings.h src/xmalloc.h src/goaccess.h src/khash.h src/sort.h src/gslist.h src/commons.h src/error.h src/gmenu.h src/gstorage.h src/parser.h src/gkhash.h src/util.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui.o src/ui.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/facss.o: src/facss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/facss.o src/facss.cpp -Isrc
build/gdashboard.o: src/gdashboard.cpp src/gdashboard.h src/ui.h src/labels.h src/xmalloc.h src/commons.h src/util.h src/settings.h src/parser.h src/gstorage.h src/error.h src/color.h src/gslist.h src/sort.h src/khash.h src/gholder.h src/gkhash.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdashboard.o src/gdashboard.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/csv.o: src/csv.cpp src/csv.h src/labels.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/gkhash.h src/util.h src/settings.h src/parser.h src/gstorage.h src/error.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/csv.o src/csv.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gholder.o: src/gholder.cpp src/commons.h src/geoip1.h src/xmalloc.h src/khash.h src/gslist.h src/sort.h src/gholder.h src/gkhash.h src/util.h src/settings.h src/gstorage.h src/parser.h src/gdns.h src/error.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gholder.o src/gholder.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/options.o: src/options.cpp src/options.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/options.o src/options.cpp -Isrc -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/websocket.o: src/websocket/websocket.cpp src/websocket/websocket.h src/websocket/base64.h src/error.h src/settings.h src/commons.h src/gslist.h src/websocket/sha1.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/websocket.o src/websocket/websocket.cpp -Isrc -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/commons.o: src/commons.cpp src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/commons.o src/commons.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/persistence.o: src/persistence.cpp src/persistence.h src/error.h src/settings.h src/util.h src/gkhash.h src/gstorage.h src/khash.h src/sort.h src/parser.h src/commons.h src/gslist.h src/tpl.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/persistence.o src/persistence.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/browsers.o: src/browsers.cpp src/browsers.h src/commons.h src/gslist.h src/error.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/browsers.o src/browsers.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdns.o: src/gdns.cpp src/gkhash.h src/xmalloc.h src/util.h src/khash.h src/goaccess.h src/settings.h src/commons.h src/color.h src/labels.h src/sort.h src/gslist.h src/ui.h src/gdns.h src/error.h src/parser.h src/gstorage.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdns.o src/gdns.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/parser.o: src/parser.cpp src/gkhash.h src/pdjson.h src/browsers.h src/xmalloc.h src/websocket/websocket.h src/commons.h src/util.h src/khash.h src/goaccess.h src/settings.h src/parser.h src/gstorage.h src/error.h src/gslist.h src/sort.h src/color.h src/labels.h src/ui.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/parser.o src/parser.cpp -Isrc -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gstorage.o: src/gstorage.cpp src/geoip1.h src/browsers.h src/opesys.h src/xmalloc.h src/labels.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui.h src/error.h src/parser.h src/gstorage.h src/gkhash.h src/util.h src/settings.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gstorage.o src/gstorage.cpp -Isrc -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/hoganjs.o: src/hoganjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/hoganjs.o src/hoganjs.cpp -Isrc
build/khash.o: src/khash.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/khash.o src/khash.cpp -Isrc
build/goaccess.exe: build/pdjson.o build/gmenu.o build/websocket/gwsocket.o build/gholder.o build/gkhash.o build/ui.o build/websocket/websocket.o build/error.o build/xmalloc.o build/json.o build/opesys.o build/persistence.o build/goaccess.o build/settings.o build/websocket/sha1.o build/util.o build/gdns.o build/browsers.o build/gdashboard.o build/commons.o build/parser.o build/geoip1.o build/gstorage.o build/options.o build/gslist.o build/websocket/base64.o build/tpl.o build/csv.o build/color.o build/output.o build/sort.o
	g++ -flto -Werror -ltcmalloc -o build/goaccess.exe build/pdjson.o build/gmenu.o build/websocket/gwsocket.o build/gholder.o build/gkhash.o build/ui.o build/websocket/websocket.o build/error.o build/xmalloc.o build/json.o build/opesys.o build/persistence.o build/goaccess.o build/settings.o build/websocket/sha1.o build/util.o build/gdns.o build/browsers.o build/gdashboard.o build/commons.o build/parser.o build/geoip1.o build/gstorage.o build/options.o build/gslist.o build/websocket/base64.o build/tpl.o build/csv.o build/color.o build/output.o build/sort.o -lGeoIP -lncurses -ltinfo -lssl -lcrypto
build/bin2c.exe: build/bin2c.o
	g++ -flto -Werror -ltcmalloc -o build/bin2c.exe build/bin2c.o -lbz2
executables: build/goaccess.exe build/bin2c.exe
makedirs:
	mkdir -p build/websocket build
