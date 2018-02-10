all:
	g++ OnlineAuctionSystem.cpp OnlineAuctionSystem.hpp -o Auction

clean:
	rm -f Auction
