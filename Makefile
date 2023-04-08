CXX = g++
CXXFLAGS = -std=c++14 -Wall
SRCS = src/owner.cpp src/parkinglot.cpp src/parkingspot.cpp src/ImpPricing.cpp src/ticket.cpp src/vehicleInfo.cpp driver/main.cpp
INCLUDES = -I includes
OBJS = $(SRCS:.cpp=.o)

all: parking_lot

parking_lot: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -g -o parking_lot

%.o: %.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -g -c $< -o $@

clean:
	rm -f ${OBJS} parking_lot includes/*.gch