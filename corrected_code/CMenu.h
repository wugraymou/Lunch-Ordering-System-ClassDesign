#ifndef CMENU_H
#define CMENU_H

#include <string>

namespace model {

class CMenu {
public:
    CMenu() = default;
    CMenu(std::string menuId, std::string name, std::string category, int price, int stock, std::string imagePath);

    // Menu maintenance
    void updatePrice(int newPrice);
    void updateStock(int newStock);
    void setImage(const std::string& path);

    // Read
    void displayMenu() const; // skeleton: could print/log
    const std::string& getMenuId() const;
    const std::string& getName() const;
    const std::string& getCategory() const;
    int getPrice() const;
    int getStock() const;
    const std::string& getImagePath() const;

private:
    std::string menuId_;
    std::string name_;
    std::string category_;
    int price_ = 0;
    int stock_ = 0;
    std::string imagePath_;
};

} // namespace model

#endif // CMENU_H
