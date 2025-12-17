#include "EOrderDetail.h"
#include "CMenu.h"
#include <algorithm>
#include <stdexcept>

namespace model {

EOrderDetail::EOrderDetail(std::string orderDetailId, std::shared_ptr<CMenu> menu, int quantity)
    : orderDetailId_(std::move(orderDetailId)), menu_(std::move(menu)) {
    updateQuantity(quantity);
}

int EOrderDetail::calcSubtotal() const {
    return subtotal_;
}

void EOrderDetail::updateQuantity(int newQty) {
    // Business rule example: 0 <= quantity <= 5000
    if (newQty < 0 || newQty > 5000) {
        throw std::out_of_range("quantity must be between 0 and 5000");
    }
    quantity_ = newQty;
    recalcSubtotal();
}

void EOrderDetail::recalcSubtotal() {
    const int price = (menu_ ? menu_->getPrice() : 0);
    subtotal_ = price * quantity_;
}

const std::string& EOrderDetail::getOrderDetailId() const { return orderDetailId_; }
int EOrderDetail::getQuantity() const { return quantity_; }
int EOrderDetail::getSubtotal() const { return subtotal_; }
std::shared_ptr<CMenu> EOrderDetail::getMenu() const { return menu_; }

} // namespace model
