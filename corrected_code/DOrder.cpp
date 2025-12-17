#include "DOrder.h"
#include "EOrderDetail.h"
#include "CMenu.h"
#include <algorithm>
#include <sstream>

namespace model {

static std::string makeDetailId(const std::string& orderId, std::size_t idx) {
    std::ostringstream oss;
    oss << orderId << "-D" << idx;
    return oss.str();
}

DOrder::DOrder(std::string orderId, std::string userId)
    : orderId_(std::move(orderId)), userId_(std::move(userId)) {}

void DOrder::addOrderDetail(const std::shared_ptr<CMenu>& menu, int quantity) {
    const std::string detailId = makeDetailId(orderId_, details_.size() + 1);
    details_.emplace_back(detailId, menu, quantity);
    recalcTotal();
}

bool DOrder::removeOrderDetail(const std::string& detailId) {
    auto it = std::remove_if(details_.begin(), details_.end(),
                             [&](const EOrderDetail& d) { return d.getOrderDetailId() == detailId; });
    if (it == details_.end()) return false;
    details_.erase(it, details_.end());
    recalcTotal();
    return true;
}

int DOrder::calcTotalAmount() const {
    return totalAmount_;
}

void DOrder::updateStatus(Status newStatus) {
    status_ = newStatus;
}

void DOrder::recalcTotal() {
    int sum = 0;
    for (const auto& d : details_) sum += d.getSubtotal();
    totalAmount_ = sum;
}

const std::string& DOrder::getOrderId() const { return orderId_; }
const std::string& DOrder::getUserId() const { return userId_; }
DOrder::Status DOrder::getStatus() const { return status_; }

std::vector<EOrderDetail> DOrder::getDetails() const { return details_; }

} // namespace model
