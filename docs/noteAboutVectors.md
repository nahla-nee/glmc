It is worth mentioning that the vector api dels with passing vectors not by
using the vector union, but rather by passing the `.vec` compnent of the union.
The reason for this is that passing the union will result in it being passed over
two registers, where as passing the `.vec` will require only one register.
