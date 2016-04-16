all:
	g++ main.cpp -I /opt/local/include -L /opt/local/lib `pkg-config --cflags --libs opencv` -o main
