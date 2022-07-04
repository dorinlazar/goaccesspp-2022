.PHONY: executables makedirs
all: makedirs executables
build/sort.o: src/sort.cpp src/ui/textui.hpp src/settings.h src/util.h src/sort.h src/parser.h src/error.hpp src/commons.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/sort.o src/sort.cpp -Isrc -Isrc -Isrc/ui -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/d3js.o: src/resources/d3js.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/d3js.o src/resources/d3js.cpp -Isrc
build/websocket/base64.o: src/websocket/base64.cpp src/websocket/base64.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/base64.o src/websocket/base64.cpp -Isrc -Isrc -Isrc/websocket
build/gslist.o: src/gslist.cpp src/gstorage.h src/parser.h src/commons.h src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gslist.o src/gslist.cpp -Isrc -Isrc
build/output.o: src/output.cpp src/resources/appcss.h src/util.h src/xmalloc.h src/color.h src/json.h src/gkhash.h src/resources/facss.h src/khash.h src/resources/appjs.h src/gstorage.h src/parser.h src/resources/bootstrapcss.h src/sort.h src/output.h src/gslist.h src/websocket/websocket.h src/commons.h src/error.hpp src/labels.h src/resources/d3js.h src/ui/textui.hpp src/resources/tpls.h src/ui/ui.h src/settings.h src/websocket/gwsocket.h src/resources/chartsjs.h src/resources/hoganjs.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/output.o src/output.cpp -Isrc -Isrc/ui -Isrc/websocket -Isrc -Isrc/resources -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/khash.o: src/khash.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/khash.o src/khash.cpp -Isrc
build/gstorage.o: src/gstorage.cpp src/geo/geoip1.h src/color.h src/xmalloc.h src/util.h src/ui/ui.h src/settings.h src/khash.h src/sort.h src/gslist.h src/commons.h src/error.hpp src/gstorage.h src/parser.h src/gkhash.h src/labels.h src/ui/textui.hpp src/opesys.h src/browsers.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gstorage.o src/gstorage.cpp -Isrc -Isrc/ui -Isrc -Isrc/geo -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gdns.o: src/gdns.cpp src/gkhash.h src/xmalloc.h src/util.h src/khash.h src/goaccess.h src/commons.h src/error.hpp src/color.h src/gdns.h src/gstorage.h src/parser.h src/sort.h src/gslist.h src/settings.h src/ui/ui.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdns.o src/gdns.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/browsers.o: src/browsers.cpp src/browsers.h src/ui/textui.hpp src/error.hpp src/commons.h src/gslist.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/browsers.o src/browsers.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/bootstrapcss.o: src/resources/bootstrapcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/bootstrapcss.o src/resources/bootstrapcss.cpp -Isrc
build/xmalloc.o: src/xmalloc.cpp src/error.hpp src/commons.h src/settings.h src/ui/textui.hpp src/gslist.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/xmalloc.o src/xmalloc.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/opsys/osutils.o: src/opsys/osutils.cpp src/opsys/osutils.hpp src/error.hpp src/commons.h src/settings.h src/ui/textui.hpp src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opsys/osutils.o src/opsys/osutils.cpp -Isrc -Isrc/ui -Isrc -Isrc/opsys -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/parser.o: src/parser.cpp src/gkhash.h src/pdjson.h src/browsers.h src/error.hpp src/xmalloc.h src/websocket/websocket.h src/commons.h src/parser.h src/gstorage.h src/util.h src/khash.h src/goaccess.h src/gslist.h src/sort.h src/color.h src/settings.h src/ui/ui.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/parser.o src/parser.cpp -Isrc -Isrc/ui -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/labels.o: src/labels.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/labels.o src/labels.cpp -Isrc
build/error.o: src/error.cpp src/error.hpp src/commons.h src/settings.h src/ui/textui.hpp src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/error.o src/error.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/opesys.o: src/opesys.cpp src/opesys.h src/ui/textui.hpp src/error.hpp src/commons.h src/gslist.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/opesys.o src/opesys.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/csv.o: src/csv.cpp src/csv.h src/error.hpp src/util.h src/color.h src/commons.h src/gslist.h src/sort.h src/khash.h src/settings.h src/ui/ui.h src/parser.h src/gstorage.h src/gkhash.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/csv.o src/csv.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/settings.o: src/settings.cpp src/util.h src/settings.h src/parser.h src/error.hpp src/commons.h src/gslist.h src/khash.h src/gstorage.h src/ui/textui.hpp src/gkhash.h src/pdjson.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/settings.o src/settings.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/persistence.o: src/persistence.cpp src/persistence.h src/xmalloc.h src/util.h src/settings.h src/tpl.h src/commons.h src/error.hpp src/gslist.h src/sort.h src/khash.h src/parser.h src/gstorage.h src/gkhash.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/persistence.o src/persistence.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/appjs.o: src/resources/appjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appjs.o src/resources/appjs.cpp -Isrc
build/resources/hoganjs.o: src/resources/hoganjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/hoganjs.o src/resources/hoganjs.cpp -Isrc
build/bin2c.o: src/bin2c.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/bin2c.o src/bin2c.cpp -Isrc -Isrc
build/websocket/sha1.o: src/websocket/sha1.cpp src/websocket/sha1.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/sha1.o src/websocket/sha1.cpp -Isrc -Isrc/websocket
build/pdjson.o: src/pdjson.cpp src/pdjson.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/pdjson.o src/pdjson.cpp -Isrc -Isrc
build/resources/appcss.o: src/resources/appcss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/appcss.o src/resources/appcss.cpp -Isrc
build/resources/facss.o: src/resources/facss.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/facss.o src/resources/facss.cpp -Isrc
build/color.o: src/color.cpp src/color.h src/error.hpp src/commons.h src/ui/textui.hpp src/gslist.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/color.o src/color.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/tpls.o: src/resources/tpls.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/tpls.o src/resources/tpls.cpp -Isrc
build/util.o: src/util.cpp src/error.hpp src/commons.h src/util.h src/settings.h src/ui/textui.hpp src/gslist.h src/labels.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/util.o src/util.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/websocket.o: src/websocket/websocket.cpp src/websocket/websocket.h src/websocket/base64.h src/error.hpp src/commons.h src/settings.h src/ui/textui.hpp src/gslist.h src/websocket/sha1.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/websocket.o src/websocket/websocket.cpp -Isrc -Isrc/ui -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/tpl.o: src/tpl.cpp src/tpl.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/tpl.o src/tpl.cpp -Isrc -Isrc
build/gdashboard.o: src/gdashboard.cpp src/gdashboard.h src/error.hpp src/xmalloc.h src/util.h src/ui/ui.h src/settings.h src/commons.h src/parser.h src/gstorage.h src/color.h src/gslist.h src/sort.h src/khash.h src/gholder.h src/gkhash.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gdashboard.o src/gdashboard.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/websocket/gwsocket.o: src/websocket/gwsocket.cpp src/websocket/gwsocket.h src/json.h src/xmalloc.h src/parser.h src/websocket/websocket.h src/commons.h src/error.hpp src/goaccess.h src/gslist.h src/sort.h src/color.h src/settings.h src/ui/ui.h src/labels.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/websocket/gwsocket.o src/websocket/gwsocket.cpp -Isrc -Isrc/ui -Isrc -Isrc/websocket -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/resources/chartsjs.o: src/resources/chartsjs.cpp 
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/resources/chartsjs.o src/resources/chartsjs.cpp -Isrc
build/gmenu.o: src/gmenu.cpp src/gmenu.h src/xmalloc.h src/ui/ui.h src/sort.h src/commons.h src/color.h src/labels.h src/parser.h src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gmenu.o src/gmenu.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gholder.o: src/gholder.cpp src/sort.h src/gslist.h src/commons.h src/error.hpp src/geo/geoip1.h src/xmalloc.h src/util.h src/settings.h src/khash.h src/gholder.h src/gkhash.h src/gstorage.h src/parser.h src/gdns.h src/ui/textui.hpp
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gholder.o src/gholder.cpp -Isrc -Isrc/ui -Isrc/geo -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/commons.o: src/commons.cpp src/ui/textui.hpp src/labels.h src/error.hpp src/commons.h src/gslist.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/commons.o src/commons.cpp -Isrc -Isrc -Isrc/ui -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/gkhash.o: src/gkhash.cpp src/gstorage.h src/gkhash.h src/ui/textui.hpp src/persistence.h src/khash.h src/sort.h src/parser.h src/error.hpp src/commons.h src/gslist.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/gkhash.o src/gkhash.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/ui/ui.o: src/ui/ui.cpp src/error.hpp src/gkhash.h src/xmalloc.h src/util.h src/goaccess.h src/khash.h src/commons.h src/color.h src/ui/textui.hpp src/labels.h src/sort.h src/gslist.h src/settings.h src/ui/ui.h src/parser.h src/gmenu.h src/gstorage.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui/ui.o src/ui/ui.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/json.o: src/json.cpp src/json.h src/error.hpp src/gkhash.h src/xmalloc.h src/ui/textui.hpp src/labels.h src/color.h src/websocket/websocket.h src/commons.h src/gslist.h src/sort.h src/khash.h src/util.h src/ui/ui.h src/settings.h src/parser.h src/gstorage.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/json.o src/json.cpp -Isrc -Isrc/websocket -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/geo/geoip1.o: src/geo/geoip1.cpp src/geo/geoip1.h src/error.hpp src/commons.h src/ui/textui.hpp src/gslist.h src/settings.h src/util.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/geo/geoip1.o src/geo/geoip1.cpp -Isrc -Isrc/ui -Isrc -Isrc/geo -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/options.o: src/options.cpp src/options.h src/error.hpp src/commons.h src/ui/textui.hpp src/gslist.h src/labels.h src/settings.h src/util.h src/xmalloc.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/options.o src/options.cpp -Isrc -Isrc/ui -Isrc -I/usr/include/ -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/ui/textui.o: src/ui/textui.cpp src/error.hpp src/commons.h src/settings.h src/ui/textui.hpp src/gslist.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/ui/textui.o src/ui/textui.cpp -Isrc -Isrc/ui -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/goaccess.o: src/goaccess.cpp src/tpl.h src/websocket/sha1.h src/resources/hoganjs.h src/resources/tpls.h src/resources/appjs.h src/resources/facss.h src/persistence.h src/resources/appcss.h src/pdjson.h src/settings.h src/error.hpp src/opesys.h src/csv.h src/color.h src/gdashboard.h src/websocket/gwsocket.h src/resources/chartsjs.h src/gmenu.h src/gholder.h src/commons.h src/util.h src/websocket/websocket.h src/json.h src/geo/geoip1.h src/options.h src/ui/textui.hpp src/goaccess.h src/ui/ui.h src/gkhash.h src/labels.h src/parser.h src/opsys/osutils.hpp src/xmalloc.h src/resources/bootstrapcss.h src/browsers.h src/gdns.h src/gstorage.h src/khash.h src/output.h src/gslist.h src/websocket/base64.h src/resources/d3js.h src/sort.h
	g++ -Wall -Wextra -c -std=c++20 -g3 -O2 -flto -Werror -o build/goaccess.o src/goaccess.cpp -Isrc -Isrc/opsys -Isrc/ui -Isrc/geo -Isrc/resources -Isrc/websocket -Isrc -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
build/bin2c.exe: build/bin2c.o
	g++ -flto -Werror -ltcmalloc -o build/bin2c.exe build/bin2c.o -lbz2
build/goaccess.exe: build/sort.o build/websocket/base64.o build/gmenu.o build/websocket/websocket.o build/persistence.o build/json.o build/error.o build/xmalloc.o build/pdjson.o build/websocket/gwsocket.o build/output.o build/color.o build/csv.o build/gslist.o build/options.o build/websocket/sha1.o build/tpl.o build/goaccess.o build/settings.o build/ui/ui.o build/gholder.o build/ui/textui.o build/gkhash.o build/geo/geoip1.o build/gdashboard.o build/commons.o build/parser.o build/opesys.o build/opsys/osutils.o build/gdns.o build/util.o build/browsers.o build/gstorage.o
	g++ -flto -Werror -ltcmalloc -o build/goaccess.exe build/sort.o build/websocket/base64.o build/gmenu.o build/websocket/websocket.o build/persistence.o build/json.o build/error.o build/xmalloc.o build/pdjson.o build/websocket/gwsocket.o build/output.o build/color.o build/csv.o build/gslist.o build/options.o build/websocket/sha1.o build/tpl.o build/goaccess.o build/settings.o build/ui/ui.o build/gholder.o build/ui/textui.o build/gkhash.o build/geo/geoip1.o build/gdashboard.o build/commons.o build/parser.o build/opesys.o build/opsys/osutils.o build/gdns.o build/util.o build/browsers.o build/gstorage.o -lfmt -lGeoIP -lncurses -ltinfo -lssl -lcrypto
executables: build/bin2c.exe build/goaccess.exe
makedirs:
	mkdir -p build/ui build/opsys build/websocket build/geo build/resources build
