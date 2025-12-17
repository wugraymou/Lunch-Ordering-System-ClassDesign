#include "AUser.h"
#include "DOrder.h"

namespace model {

AUser::AUser(std::string userId, std::string account, std::string password)
    : userId_(std::move(userId)), account_(std::move(account)), password_(std::move(password)) {}

bool AUser::login(const std::string& account, const std::string& password) const {
    // Skeleton: real system would check hashed password, lockouts, etc.
    return (account == account_) && (password == password_);
}

void AUser::logout() {
    // Skeleton: session/token invalidation would live elsewhere.
}

bool AUser::registerAccount(const std::string& account, const std::string& password) {
    // Skeleton: real system would validate uniqueness, strength rules, etc.
    account_ = account;
    password_ = password;
    return true;
}

std::vector<std::shared_ptr<DOrder>> AUser::viewOrderHistory() const {
    return orderHistory_;
}

void AUser::addOrderToHistory(const std::shared_ptr<DOrder>& order) {
    if (order) orderHistory_.push_back(order);
}

const std::string& AUser::getUserId() const { return userId_; }
const std::string& AUser::getAccount() const { return account_; }

void AUser::setPassword(const std::string& newPassword) { password_ = newPassword; }

} // namespace model
