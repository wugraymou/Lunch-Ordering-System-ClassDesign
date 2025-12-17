#include "AUser.h"
#include "BStaff.h"
#include "CMenu.h"
#include "DOrder.h"
#include "FFeedback.h"
#include <iostream>
#include <memory>

int main() {
    using namespace model;

    auto ramen = std::make_shared<CMenu>("M001", "Ramen", "Main", 180, 50, "ramen.jpg");

    AUser user("U001", "alice", "pw123");
    auto order = std::make_shared<DOrder>("O001", user.getUserId());
    order->addOrderDetail(ramen, 2);

    user.addOrderToHistory(order);

    std::cout << "Total = " << order->calcTotalAmount() << "\n";

    FFeedback fb("F001", order->getOrderId(), ramen->getMenuId());
    fb.addFeedback(5, "Great!");
    fb.addReply("Thanks!");

    std::cout << "Rating=" << fb.getRating() << " Score=" << fb.getScore() << "\n";
    return 0;
}
