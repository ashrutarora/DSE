#include <iostream>
using namespace std;
class Polynomial
{
public:
    // polynomial node class
    class node
    {
    public:
        int co, exp;
        node *next;
        node(int co = 0, int exp = 0)
        {
            this->co = co;
            this->exp = exp;
            this->next = NULL;
        }
    };
    node *create(node *head, int co, int exp);
    node *polyAdd(node *p1, node *p2, node *sum);
    void display(node *head);
};
// create a polynomial
Polynomial::node *Polynomial::create(node *head, int co, int exp)
{
    node *temp, *flag;
    // if polynomial empty. make the node the head node
    if (head == NULL)
    {
        temp = new node(co, exp);
        head = temp;
    }
    else
    {
        // else go to the last node and append
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        flag = new node(co, exp);
        temp->next = flag;
    }
    return head;
}
// add two polynomial
Polynomial::node *Polynomial::polyAdd(node *p1, node *p2, node *sum)
{
    // copy the two polynomial and initialize variable res to store the sum
    node *poly1 = p1, *poly2 = p2, *res;
    // if polynomial 2 is null, set polynomial 1 as the sum
    if (poly1 != NULL && poly2 == NULL)
    {
        sum = poly1;
        return sum;
    }
    // if polynomial 1 is null, set polynomial 2 as the sum
    else if (poly1 == NULL && poly2 != NULL)
    {
        sum = poly2;
        return sum;
    }
    // if both polynomials are non-empty
    while (poly1 != NULL && poly2 != NULL)
    {
        // if the sum is empty, initialize sum with a node structure
        // and set res equal to sum
        if (sum == NULL)
        {
            sum = new node();
            res = sum;
        }
        // add a new node structure at the end of res to store sum
        else
        {
            res->next = new node();
            res = res->next;
        }

        if (poly1->exp > poly2->exp)
        {
            res->co = poly1->co;
            res->exp = poly1->exp;
            poly1 = poly1->next;
        }
        // if exponent of current node of polynomial 2 is greater than that of polynomial 1
        // add it to the sum
        else if (poly1->exp < poly2->exp)
        {
            res->co = poly2->co;
            res->exp = poly2->exp;
            poly2 = poly2->next;
        }
        // if exponent of current node of polynomial 1 is equal to that of polynomial 2
        // add the sum of their co-efficient to the sum
        else if (poly1->exp == poly2->exp)
        {
            res->co = poly1->co + poly2->co;
            res->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // if polynomial 1 is non-empty add the remaining nodes to the sum
    while (poly1 != NULL)
    {
        res->next = new node();
        res = res->next;
        res->co = poly1->co;
        res->exp = poly1->exp;
        poly1 = poly1->next;
    }
    // if polynomial 2 is non-empty add the remaining nodes to the sum
    while (poly2 != NULL)
    {
        res->next = new node();
        res = res->next;
        res->co = poly2->co;
        res->exp = poly2->exp;
        poly2 = poly2->next;
    }

    res->next = NULL;

    return sum;
}

void Polynomial::display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->co << "^" << temp->exp << "+";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // to store polynomial 1, polynomial 2 and the sum
    Polynomial poly;
    Polynomial::node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int ch, co, exp;
    int loop = 1;
    while (loop)
    {
        cout << "1. Add to Polynomial 1" << endl;
        cout << "2. Add to Polynomial 2" << endl;
        cout << "3. Perform Addition" << endl;
        cout << "4. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter co-efficient" << endl;
            cin >> co;
            cout << "Enter exponent" << endl;
            cin >> exp;
            p1 = poly.create(p1, co, exp);
            break;
        case 2:
            cout << "Enter co-efficient" << endl;
            cin >> co;
            cout << "Enter exponent" << endl;
            cin >> exp;
            p2 = poly.create(p2, co, exp);
            break;
        case 3:
            sum = poly.polyAdd(p1, p2, sum);
            cout << endl
                 << "Polynomial 1" << endl;
            poly.display(p1);
            cout << endl
                 << "Polynomial 2" << endl;
            poly.display(p2);

            cout << endl
                 << "Sum: " << endl;
            poly.display(sum);
            break;

        case 4:
            loop = 0;
            break;
        default:
            cout << "Wrong Choice! Re-enter";
            break;
        }
    }
    return 0;
}