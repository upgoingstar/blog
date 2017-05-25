/**
* A view class that controls interface with user
*/
class UserView {
private:
	/*
	 * Renderiza tela para preenchimento
	 * Somente imprime 'Preencha seu nome:' e retorna 
	 */
	Name field_name_page();
	/*
	 * Renderiza tela para preenchimento
	 * Somente imprime 'Preencha seu email:' e retorna 
	 */
	Email field_email_page();
	/*
	 * Renderiza tela para preenchimento
	 * Somente imprime 'Preencha sua senha:' e retorna 
	 */
	Password field_password_page();
public:
	/*
	 * Renderiza tela de login
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void login_page();
	/*
	 * Renderiza tela de sign_up
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void signup_page();
	/*
	 * Renderiza tela de perfil
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void profile_page();
}