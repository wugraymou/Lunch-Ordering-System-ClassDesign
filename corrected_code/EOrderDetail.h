#ifndef EORDERDETAIL_H
#define EORDERDETAIL_H

#include <string>
#include <memory>

namespace model {

class CMenu;

class EOrderDetail {
public:
    EOrderDetail() = default;
    EOrderDetail(std::string orderDetailId, std::shared_ptr<CMenu> menu, int quantity);

    int calcSubtotal() const;
    void updateQuantity(int newQty);

    const std::string& getOrderDetailId() const;
    int getQuantity() const;
    int getSubtotal() const;

    std::shared_ptr<CMenu> getMenu() const;

private:
    std::string orderDetailId_;
    std::shared_ptr<CMenu> menu_;
    int quantity_ = 0;
    int subtotal_ = 0;

    void recalcSubtotal();
};

} // namespace model

#endif // EORDERDETAIL_H
