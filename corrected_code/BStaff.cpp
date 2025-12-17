#include "BStaff.h"
#include "CMenu.h"

namespace model {

BStaff::BStaff(std::string staffId, std::string account, std::string password)
    : staffId_(std::move(staffId)), account_(std::move(account)), password_(std::move(password)) {}

bool BStaff::login(const std::string& account, const std::string& password) const {
    return (account == account_) && (password == password_);
}

void BStaff::uploadMenu(const std::shared_ptr<CMenu>& menu) {
    if (menu) managedMenus_.push_back(menu);
}

bool BStaff::updateStock(const std::string& menuId, int newStock) {
    for (auto& m : managedMenus_) {
        if (m && m->getMenuId() == menuId) {
            m->updateStock(newStock);
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<DOrder>> BStaff::viewOrders() const {
    return orderView_;
}

void BStaff::setOrderView(const std::vector<std::shared_ptr<DOrder>>& orders) {
    orderView_ = orders;
}

const std::string& BStaff::getStaffId() const { return staffId_; }

} // namespace model
