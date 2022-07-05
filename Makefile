.PHONY: executables makedirs
all: makedirs executables
build/gmenu.o: src/gmenu.cpp src/gmenu.h src/util/xmalloc.h src/ui/ui.h src/sort.h src/gslist.h src/commons.h src/parser.h src/color.h src/labels.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gmenu.o src/gmenu.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gslist.o: src/gslist.cpp src/parser.h src/commons.h src/gslist.h src/gstorage.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gslist.o src/gslist.cpp -Isrc -Isrc/util -Isrc
build/output.o: src/output.cpp src/util/xmalloc.h src/json.h src/resources/appcss.h src/util/util.h src/color.h src/websocket/gwsocket.h src/resources/hoganjs.h src/resources/chartsjs.h src/resources/appjs.h src/resources/bootstrapcss.h src/sort.h src/output.h src/gslist.h src/websocket/websocket.h src/commons.h src/labels.h src/resources/d3js.h src/ui/textui.hpp src/gkhash.h src/resources/tpls.h src/ui/ui.h src/settings.h src/util/error.hpp src/parser.h src/gstorage.h src/resources/facss.h src/khash.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/output.o src/output.cpp -Isrc -Isrc/ui -Isrc/websocket -Isrc/resources -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gstorage.o: src/gstorage.cpp src/util/xmalloc.h src/geo/geoip1.h src/color.h src/util/util.h src/commons.h src/sort.h src/gslist.h src/khash.h src/gstorage.h src/parser.h src/gkhash.h src/ui/ui.h src/settings.h src/util/error.hpp src/opesys.h src/browsers.h src/ui/textui.hpp src/labels.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gstorage.o src/gstorage.cpp -Isrc -Isrc/ui -Isrc -Isrc/geo -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/parser.o: src/parser.cpp src/gkhash.h src/browsers.h src/util/error.hpp src/util/util.h src/pdjson.h src/util/xmalloc.h src/websocket/websocket.h src/commons.h src/gstorage.h src/parser.h src/gslist.h src/sort.h src/color.h src/khash.h src/goaccess.h src/ui/ui.h src/settings.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/parser.o src/parser.cpp -Isrc -Isrc/ui -Isrc/websocket -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdns.o: src/gdns.cpp src/gkhash.h src/util/xmalloc.h src/util/util.h src/sort.h src/gslist.h src/commons.h src/gdns.h src/gstorage.h src/parser.h src/color.h src/khash.h src/goaccess.h src/ui/ui.h src/settings.h src/labels.h src/ui/textui.hpp src/util/error.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdns.o src/gdns.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/commons.o: src/commons.cpp src/util/error.hpp src/ui/textui.hpp src/labels.h src/settings.h src/commons.h src/gslist.h src/util/util.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/commons.o src/commons.cpp -Isrc -Isrc -Isrc/ui -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/websocket.o: src/websocket/websocket.cpp src/websocket/websocket.h src/websocket/base64.h src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/websocket/sha1.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/websocket.o src/websocket/websocket.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/settings.o: src/settings.cpp src/util/error.hpp src/settings.h src/parser.h src/khash.h src/gslist.h src/commons.h src/ui/textui.hpp src/gkhash.h src/pdjson.h src/labels.h src/util/util.h src/gstorage.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/settings.o src/settings.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gholder.o: src/gholder.cpp src/sort.h src/gslist.h src/commons.h src/geo/geoip1.h src/util/xmalloc.h src/util/util.h src/khash.h src/gholder.h src/gkhash.h src/gstorage.h src/parser.h src/gdns.h src/ui/textui.hpp src/settings.h src/util/error.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gholder.o src/gholder.cpp -Isrc -Isrc/ui -Isrc/util -Isrc/geo -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/sha1.o: src/websocket/sha1.cpp src/websocket/sha1.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/sha1.o src/websocket/sha1.cpp -Isrc -Isrc/websocket
build/gkhash.o: src/gkhash.cpp src/util/error.hpp src/settings.h src/gkhash.h src/ui/textui.hpp src/persistence.h src/util/util.h src/khash.h src/sort.h src/parser.h src/commons.h src/gslist.h src/gstorage.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gkhash.o src/gkhash.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/browsers.o: src/browsers.cpp src/browsers.h src/util/error.hpp src/ui/textui.hpp src/settings.h src/commons.h src/gslist.h src/util/util.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/browsers.o src/browsers.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/opsys/osutils.o: src/opsys/osutils.cpp src/opsys/osutils.hpp src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opsys/osutils.o src/opsys/osutils.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -Isrc/opsys -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/labels.o: src/labels.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/labels.o src/labels.cpp -Isrc
build/persistence.o: src/persistence.cpp src/util/xmalloc.h src/commons.h src/gstorage.h src/parser.h src/gslist.h src/sort.h src/khash.h src/gkhash.h src/ui/textui.hpp src/tpl.h src/settings.h src/util/error.hpp src/persistence.h src/util/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/persistence.o src/persistence.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/appjs.o: src/resources/appjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appjs.o src/resources/appjs.cpp -Isrc
build/pdjson.o: src/pdjson.cpp src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/pdjson.o src/pdjson.cpp -Isrc -Isrc
build/opesys.o: src/opesys.cpp src/opesys.h src/util/error.hpp src/ui/textui.hpp src/settings.h src/commons.h src/gslist.h src/util/util.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opesys.o src/opesys.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/bootstrapcss.o: src/resources/bootstrapcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/bootstrapcss.o src/resources/bootstrapcss.cpp -Isrc
build/resources/appcss.o: src/resources/appcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appcss.o src/resources/appcss.cpp -Isrc
build/websocket/base64.o: src/websocket/base64.cpp src/websocket/base64.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/base64.o src/websocket/base64.cpp -Isrc -Isrc/util -Isrc/websocket
build/resources/hoganjs.o: src/resources/hoganjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/hoganjs.o src/resources/hoganjs.cpp -Isrc
build/util/util.o: src/util/util.cpp src/util/util.h src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/labels.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util/util.o src/util/util.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/color.o: src/color.cpp src/color.h src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/util/util.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/color.o src/color.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/chartsjs.o: src/resources/chartsjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/chartsjs.o src/resources/chartsjs.cpp -Isrc
build/resources/d3js.o: src/resources/d3js.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/d3js.o src/resources/d3js.cpp -Isrc
build/geo/geoip1.o: src/geo/geoip1.cpp src/geo/geoip1.h src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/util/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/geo/geoip1.o src/geo/geoip1.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -Isrc/geo -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/goaccess.o: src/goaccess.cpp src/resources/facss.h src/resources/d3js.h src/resources/bootstrapcss.h src/resources/appjs.h src/resources/chartsjs.h src/resources/hoganjs.h src/resources/appcss.h src/opesys.h src/websocket/base64.h src/persistence.h src/pdjson.h src/util/util.h src/color.h src/websocket/gwsocket.h src/csv.h src/util/xmalloc.h src/khash.h src/json.h src/gdashboard.h src/options.h src/ui/textui.hpp src/ui/ui.h src/resources/tpls.h src/sort.h src/tpl.h src/util/error.hpp src/geo/geoip1.h src/goaccess.h src/labels.h src/opsys/osutils.hpp src/browsers.h src/gkhash.h src/websocket/sha1.h src/gholder.h src/settings.h src/websocket/websocket.h src/commons.h src/gdns.h src/parser.h src/gstorage.h src/output.h src/gslist.h src/gmenu.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/goaccess.o src/goaccess.cpp -Isrc -Isrc/opsys -Isrc/geo -Isrc/ui -Isrc/util -Isrc/websocket -Isrc -Isrc/resources -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/facss.o: src/resources/facss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/facss.o src/resources/facss.cpp -Isrc
build/bin2c.o: src/bin2c.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/bin2c.o src/bin2c.cpp -Isrc -Isrc
build/websocket/gwsocket.o: src/websocket/gwsocket.cpp src/websocket/gwsocket.h src/json.h src/util/xmalloc.h src/parser.h src/websocket/websocket.h src/commons.h src/goaccess.h src/gslist.h src/sort.h src/color.h src/settings.h src/ui/ui.h src/labels.h src/ui/textui.hpp src/util/error.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/gwsocket.o src/websocket/gwsocket.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/csv.o: src/csv.cpp src/csv.h src/util/error.hpp src/util/util.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/parser.h src/gstorage.h src/gkhash.h src/labels.h src/ui/textui.hpp src/ui/ui.h src/settings.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/csv.o src/csv.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/util/xmalloc.o: src/util/xmalloc.cpp src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util/xmalloc.o src/util/xmalloc.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/khash.o: src/khash.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/khash.o src/khash.cpp -Isrc
build/json.o: src/json.cpp src/util/error.hpp src/gkhash.h src/json.h src/util/xmalloc.h src/gstorage.h src/parser.h src/util/util.h src/ui/textui.hpp src/labels.h src/color.h src/websocket/websocket.h src/commons.h src/gslist.h src/sort.h src/khash.h src/ui/ui.h src/settings.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/json.o src/json.cpp -Isrc -Isrc/websocket -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdashboard.o: src/gdashboard.cpp src/gdashboard.h src/util/util.h src/util/xmalloc.h src/commons.h src/gstorage.h src/parser.h src/labels.h src/ui/textui.hpp src/ui/ui.h src/settings.h src/util/error.hpp src/color.h src/gslist.h src/sort.h src/khash.h src/gkhash.h src/gholder.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdashboard.o src/gdashboard.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/options.o: src/options.cpp src/options.h src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h src/labels.h src/util/util.h src/util/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/options.o src/options.cpp -Isrc -Isrc/ui -Isrc/util -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/ui/textui.o: src/ui/textui.cpp src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui/textui.o src/ui/textui.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/ui/ui.o: src/ui/ui.cpp src/util/error.hpp src/gkhash.h src/util/util.h src/sort.h src/gslist.h src/commons.h src/color.h src/ui/textui.hpp src/labels.h src/settings.h src/ui/ui.h src/khash.h src/goaccess.h src/util/xmalloc.h src/parser.h src/gmenu.h src/gstorage.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui/ui.o src/ui/ui.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/tpls.o: src/resources/tpls.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/tpls.o src/resources/tpls.cpp -Isrc
build/sort.o: src/sort.cpp src/util/error.hpp src/ui/textui.hpp src/settings.h src/util/util.h src/sort.h src/parser.h src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/sort.o src/sort.cpp -Isrc -Isrc -Isrc/ui -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/util/error.o: src/util/error.cpp src/util/error.hpp src/settings.h src/ui/textui.hpp src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util/error.o src/util/error.cpp -Isrc -Isrc/ui -Isrc -Isrc/util -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/tpl.o: src/tpl.cpp src/tpl.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/tpl.o src/tpl.cpp -Isrc -Isrc
build/goaccess.exe: build/gmenu.o build/gstorage.o build/persistence.o build/gslist.o build/options.o build/websocket/gwsocket.o build/util/xmalloc.o build/ui/textui.o build/gkhash.o build/gholder.o build/output.o build/csv.o build/color.o build/websocket/websocket.o build/pdjson.o build/websocket/base64.o build/util/util.o build/goaccess.o build/sort.o build/tpl.o build/json.o build/util/error.o build/geo/geoip1.o build/opesys.o build/opsys/osutils.o build/websocket/sha1.o build/browsers.o build/gdns.o build/ui/ui.o build/settings.o build/gdashboard.o build/commons.o build/parser.o
	g++ -flto -Werror -ltcmalloc -o build/goaccess.exe build/gmenu.o build/gstorage.o build/persistence.o build/gslist.o build/options.o build/websocket/gwsocket.o build/util/xmalloc.o build/ui/textui.o build/gkhash.o build/gholder.o build/output.o build/csv.o build/color.o build/websocket/websocket.o build/pdjson.o build/websocket/base64.o build/util/util.o build/goaccess.o build/sort.o build/tpl.o build/json.o build/util/error.o build/geo/geoip1.o build/opesys.o build/opsys/osutils.o build/websocket/sha1.o build/browsers.o build/gdns.o build/ui/ui.o build/settings.o build/gdashboard.o build/commons.o build/parser.o -lfmt -lGeoIP -lncurses -ltinfo -lssl -lcrypto
build/bin2c.exe: build/bin2c.o
	g++ -flto -Werror -ltcmalloc -o build/bin2c.exe build/bin2c.o -lbz2
executables: build/goaccess.exe build/bin2c.exe
makedirs:
	mkdir -p build/ui build/util build/geo build/resources build/opsys build/websocket build
