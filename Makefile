all:
	g++ OnlineAuctionSystem.cpp OnlineAuctionSystem.h -o Auction

clean:
	rm -f Auction
