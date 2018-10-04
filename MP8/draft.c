int last_combined_row, temp, i, j, k, c = -1;
	for (i = 0; i < (*cur_game).cols; i++)
	{	
		last_combined_row = -1;
		for (j = 0; j < (*cur_game).rows; j++)
		{
			if ((*cur_game).cells[j * (*cur_game).cols + i] != -1)
			{
				for (k = 0; k < j; k++)
				{
					if ((*cur_game).cells[k * (*cur_game).cols + i] == -1)
					{		
						temp = (*cur_game).cells[k * (*cur_game).cols + i];			
						(*cur_game).cells[k * (*cur_game).cols + i] = (*cur_game).cells[j * (*cur_game).cols + i];
						(*cur_game).cells[j * (*cur_game).cols + i] = temp;
						c = 1;
						break;
					}
				}
				if (last_combined_row != k - 1)
				{
					if ((*cur_game).cells[(k - 1) * (*cur_game).cols + i] == (*cur_game).cells[k * (*cur_game).cols + i])
						{
							(*cur_game).cells[(k - 1) * (*cur_game).cols + i] += (*cur_game).cells[k * (*cur_game).cols + i];
							(*cur_game).cells[k * (*cur_game).cols + i] = -1;
							cur_game-> score += cur_game-> cells[(k - 1) * (*cur_game).cols+ i];
							last_combined_row = k - 1;
							c = 1;
						}
				}
			}
		}	
	}
	if (c == 1)	
	{			
    	return 1;
	}
	else
	{
