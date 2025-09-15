#include "Serialize.hpp"

int	main(void)
{
	Data	d = {123};

	// Serialize the pointer
	uintptr_t	raw = Serialize::serialize(&d);
	std::cout << "Serialized value: " << raw << "\n";

	// Deserialize back into a pointer
	Data*	p = Serialize::deserialize(raw);
	std::cout << "Deserialized pointer value: " << p->num << "\n";

	return (0);
}