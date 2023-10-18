#include "monty.h"

/**
 * get_opcodes - get an array of opcodes instruction_t
 *
 * Return: array of opcodes instruction_t
 */
instruction_t *get_opcodes()
{
	static instruction_t opcodes[] = {
		{"push", push_to_stack},
		{"pall", print_all_element_of_stack},
		{"pint", print_value_at_top},
		{"pop", pop_value_at_top},
		{"swap", swap_top_two_values},
		{"add", add_top_two_values},
		{"nop", do_nothing_on_stack},
		{NULL, NULL}};

	return (opcodes);
}
