all:
	g++ OnlineAuctionSystem.cpp OnlineAuctionSystem.hpp Login.cpp Login.hpp mainMenu.cpp mainMenu.hpp advertiseItem.cpp advertiseItem.hpp deleteUser.cpp deleteUser.hpp Users.cpp Users.hpp Logout.hpp Logout.cpp createUser.cpp createUser.hpp addCredit.cpp addCredit.hpp refundCredit.cpp refundCredit.hpp -std=c++11 -g -o Auction

clean:
	rm -f Auction