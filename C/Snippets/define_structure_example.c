// Example of how to create and populate a structure
struct customer_db
{
    int account;
    int balance;
    char name[40];
    char address[80];
    char phone[15];
};

customer_db customer;   // customer_db structure variable

// populate members individually
customer.account = 156487;
customer.balance = 375;
customer.name = "Jae Logan";
customer.address = "34 Blue Drive"
customer.phone = "845-462-6497"

// populate members at once
customer_db customer = {189654, 800, "Tom Joyner", "462 Ridge Street", "756-536-7485"};
