#include "CMenu.h"
#include <iostream>

namespace model {

CMenu::CMenu(std::string menuId, std::string name, std::string category, int price, int stock, std::string imagePath)
    : menuId_(std::move(menuId)),
      name_(std::move(name)),
      category_(std::move(category)),
      price_(price),
      stock_(stock),
      imagePath_(std::move(imagePath)) {}

void CMenu::updatePrice(int newPrice) { price_ = newPrice; }
void CMenu::updateStock(int newStock) { stock_ = newStock; }
void CMenu::setImage(const std::string& path) { imagePath_ = path; }

void CMenu::displayMenu() const {
    // skeleton output
    std::cout << "Menu[" << menuId_ << "] " << name_ << " (" << category_ << ") "
              << "price=" << price_ << ", stock=" << stock_ << "\n";
}

const std::string& CMenu::getMenuId() const { return menuId_; }
const std::string& CMenu::getName() const { return name_; }
const std::string& CMenu::getCategory() const { return category_; }
int CMenu::getPrice() const { return price_; }
int CMenu::getStock() const { return stock_; }
const std::string& CMenu::getImagePath() const { return imagePath_; }

} // namespace model
