#ifndef AUSER_H
#define AUSER_H

#include <string>
#include <vector>
#include <memory>

namespace model {

class DOrder;

class AUser {
public:
    AUser() = default;
    AUser(std::string userId, std::string account, std::string password);

    // Authentication / account
    bool login(const std::string& account, const std::string& password) const;
    void logout();
    bool registerAccount(const std::string& account, const std::string& password);

    // Orders
    std::vector<std::shared_ptr<DOrder>> viewOrderHistory() const;
    void addOrderToHistory(const std::shared_ptr<DOrder>& order);

    // Getters (keep attributes encapsulated)
    const std::string& getUserId() const;
    const std::string& getAccount() const;

    // Setters (optional)
    void setPassword(const std::string& newPassword);

private:
    std::string userId_;
    std::string account_;
    std::string password_;

    std::vector<std::shared_ptr<DOrder>> orderHistory_;
};

} // namespace model

#endif // AUSER_H
