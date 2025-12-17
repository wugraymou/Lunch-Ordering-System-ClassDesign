#ifndef BSTAFF_H
#define BSTAFF_H

#include <string>
#include <vector>
#include <memory>

namespace model {

class CMenu;
class DOrder;

class BStaff {
public:
    BStaff() = default;
    BStaff(std::string staffId, std::string account, std::string password);

    bool login(const std::string& account, const std::string& password) const;

    // Menu maintenance
    void uploadMenu(const std::shared_ptr<CMenu>& menu);                // add new menu item
    bool updateStock(const std::string& menuId, int newStock);          // update an existing item

    // Order viewing (read-only)
    std::vector<std::shared_ptr<DOrder>> viewOrders() const;
    void setOrderView(const std::vector<std::shared_ptr<DOrder>>& orders);

    // Getters
    const std::string& getStaffId() const;

private:
    std::string staffId_;
    std::string account_;
    std::string password_;

    std::vector<std::shared_ptr<CMenu>> managedMenus_;
    std::vector<std::shared_ptr<DOrder>> orderView_;
};

} // namespace model

#endif // BSTAFF_H
