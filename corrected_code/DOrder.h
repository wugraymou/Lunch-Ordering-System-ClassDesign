#ifndef DORDER_H
#define DORDER_H

#include <string>
#include <vector>
#include <memory>
#include <string>
#include <vector>
#include <memory>
#include <chrono>

#include "EOrderDetail.h"

namespace model {

class CMenu;

class DOrder {
public:
    enum class Status { Pending, Paid, Preparing, Completed, Cancelled };

    DOrder() = default;
    DOrder(std::string orderId, std::string userId);

    void addOrderDetail(const std::shared_ptr<CMenu>& menu, int quantity);
    bool removeOrderDetail(const std::string& detailId);

    int calcTotalAmount() const;
    void updateStatus(Status newStatus);

    const std::string& getOrderId() const;
    const std::string& getUserId() const;
    Status getStatus() const;

    std::vector<EOrderDetail> getDetails() const;

private:
    std::string orderId_;
    std::string userId_;
    std::chrono::system_clock::time_point orderTime_ = std::chrono::system_clock::now();
    int totalAmount_ = 0;
    Status status_ = Status::Pending;

    std::vector<EOrderDetail> details_;

    void recalcTotal();
};

} // namespace model

#endif // DORDER_H
