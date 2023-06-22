#include "monty.h"

/**
 * interpret_file - push value
 * @stack: pointer to a pointer
 * @filename: number
 *
 * Return: nothing
 */
void interpret_file(const char *filename, stack_t **stack)
{
	char line[512];
	unsigned int line_number = 1;
	FILE *file = fopen(filename, "r");
	int value;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \t\n");
		if (opcode != NULL && strcmp(opcode, "push") == 0)
		{
			char *value_str = strtok(NULL, " \t\n");
			if (value_str == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}

			value = atoi(value_str);

			if (value != 0 || strcmp(value_str, "0") == 0)
			{
				push(stack, value);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (opcode != NULL && strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (opcode != NULL)
        {
            instruction_t instructions[] = {
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
            };

            int i;
            int num_instructions = sizeof(instructions) / sizeof(instruction_t);
            for (i = 0; i < num_instructions; i++)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(stack, line_number);
                    break;
                }
            }

            if (i == num_instructions)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
		line_number++;
	}
	fclose(file);
}
