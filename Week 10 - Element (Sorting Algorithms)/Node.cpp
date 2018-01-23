#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node():element(0), next(nullptr)
{
}
Node::Node(const Element& elmt):element(elmt), next(nullptr)
{
}