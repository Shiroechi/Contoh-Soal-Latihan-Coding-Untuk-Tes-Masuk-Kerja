#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char original_text[] = " Saya Sedang ,Mengikuti kuliah Algoritma Pemograman    !!!!!!   !   .Saya lapar!b72311.a341asdasda,2334 .";
	char fixed_text[100] = "";
	int fixed_pointer = 0;

	int i = 0;
	// trim start
	while (original_text[i]) 
	{
		if (original_text[i] != ' ')
		{
			break;
		}
		i++;
	}

	// Fix first character case
	if (original_text[i])
	{
		if (isalpha(original_text[i]))
		{
			fixed_text[fixed_pointer] = toupper(original_text[i]);
			fixed_pointer = fixed_pointer + 1;
		}
	}

	bool prev_is_space = false;
	bool prev_is_punct = false;
	bool next_upper = false;
	char space = ' ';
	while (original_text[i])
	{
		i++;

		// check spaces
		if (original_text[i] == ' ')
		{
			prev_is_punct = false;

			// Traling space
			if (prev_is_space)
			{
				// If next char of trailing space is punctuation then remove space.
				char next_char = original_text[i + 1];
				if (next_char == ',' || next_char == '.' || next_char == '!' || next_char == '?')
				{
					fixed_pointer = fixed_pointer - 1;
				}
				continue;
			}

			// Remove space before punctuations
			char next_char = original_text[i + 1];
			if (next_char == ',' || next_char == '.' || next_char == '!' || next_char == '?')
			{
				continue;
			}

			// append
			fixed_text[fixed_pointer] = space;
			fixed_pointer = fixed_pointer + 1;

			prev_is_space = true;
		}
		// check punctuations
		else if (original_text[i] == ',' || original_text[i] == '.' || original_text[i] == '!' || original_text[i] == '?')
		{
			prev_is_space = false;

			// Ignore trailing punctuations
			if (prev_is_punct)
			{
				continue;
			}

			// append
			fixed_text[fixed_pointer] = original_text[i];
			fixed_pointer = fixed_pointer + 1;

			// if next char after punctuation is not space, then add space.
			char next_char = original_text[i + 1];
			if (next_char)
			{
				if (next_char != ' ')
				{
					// append
					fixed_text[fixed_pointer] = space;
					fixed_pointer = fixed_pointer + 1;
				}
			}

			if (original_text[i] == '.' || original_text[i] == '!' || original_text[i] == '?')
			{
				next_upper = true;
			}
			prev_is_punct = true;
		}
		// check alpha numerics
		else if (isalnum(original_text[i]))
		{
			prev_is_space = false;
			prev_is_punct = false;

			if (next_upper)
			{
				fixed_text[fixed_pointer] = toupper(original_text[i]);
				next_upper = false;
			}
			else
			{
				fixed_text[fixed_pointer] = tolower(original_text[i]);
			}
			fixed_pointer = fixed_pointer + 1;
		}
	}

	printf("Original:\n%s\n\n", original_text);
	printf("Fixed:\n%s", fixed_text);

	return 0;
}