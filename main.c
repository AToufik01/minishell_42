#include "minishell.h"

char	**init_path_env(char *env[])
{
	char **str;
	while (env && *env && ft_strncmp(*env, "PATH=", 5) != 0)
        env++;
	if (*env == NULL)
		printf("Path not found");
	*env += 5;
	// printf("hhhhhhhhh\n");
	str = ft_split(*env, ':');
	if (!str)
		printf("Invalid argument");
	return (str);
}


int main(int argc, char *argv[], char **env)
{
	char *input;
	t_lst_env *lst_env;
	char **env_path;
	lst_env = NULL;

	if (argc > 1)
	{
		printf("%s", argv[0]);
		return (1);
	}
	init_env(&lst_env, env);
	env_path = init_path_env(env);

	// print_lst_env(lst_env);
	
	while (1)
	{
		t__lst_token *t = NULL;
		t_cmd *cmd = NULL;
		input = readline(ANSI_COLOR_CYAN "~ " ANSI_COLOR_BLUE "minishell 😎 " ANSI_COLOR_MAGENTA "↪ " ANSI_COLOR_RESET);
		if (input == NULL)
			return (1);
		add_history(input);
		// input = readline("minishell -> ");
		// ft__lst_tokenize(&t, input);
		// ft_heredoc(&lst_env);
		if (ft__lst_tokenize(&t, input) || generate_errors(&t) == 1)
			continue;
		ft_expand(&t, &lst_env);
		ft_join(&t);
		// print__lst_tokens(t);
		ft_cmd(&cmd, &t);
		ft_lst_cmd(cmd,env_path);
		// sleep(2);
		input = "";
	}
	return 0;
}