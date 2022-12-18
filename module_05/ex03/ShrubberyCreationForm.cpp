/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:14:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 09:38:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation", 145, 137),
	_target("Default")
{
	std::cout 
		<< std::setw(25) << "[ShrubberyCreationForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("shrubbery creation", 145, 137),
	_target(target)
{
	std::cout 
		<< std::setw(25) << "[ShrubberyCreationForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref):
	AForm(ref.get_name(), ref.get_grad_to_sign(), ref.get_grad_to_execute()),
	_target(ref.get_target())
{
	std::cout 
		<< std::setw(25) << "[ShrubberyCreationForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "copy!!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout 
		<< std::setw(25) << "[ShrubberyCreationForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "delete!!" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	this->set_signed(ref.get_signed());
	this->set_target(ref.get_target());
	std::cout 
		<< std::setw(25) << "[ShrubberyCreationForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "operator=!!" << std::endl;
	return (*this);
}

std::string	ShrubberyCreationForm::get_target() const { return (this->_target); }
void	ShrubberyCreationForm::set_target(std::string target) { this->_target = target; }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	file;
	std::string		tree;

	tree =
		"                                         @@6@                             \n"
		"                                        @C6CC@                            \n"
		"                        O@C#           RCCCC6@                            \n"
		"                       KCGCCCO@      /CCCCOe@                             \n"
		"                       O66CCCCCC@   @CCCCeK                               \n"
		"                        @ReeOCCCCCCCCCCGe/                                \n"
		"                             #@eeCCCCCe@                                  \n"
		"                                  eCCe@                                   \n"
		"    @((6666@                      /CCe/                                   \n"
		"   %((((6666O                      KCG/                                   \n"
		"  @(((((666##@     OO/           #@@CC@C6@/                               \n"
		"  %((((6666###  @((((666/     RCCCCOCCKeeCCC7                             \n"
		"  @6666666###@ ((((((66O#@   CCCCCCCCCCCCCCCe                             \n"
		"   666666O### @6%(((666###   CCCCCCCCCCCCCCCeO                   #@O      \n"
		"    @######@  #6666666####   CCCCC CCCCC CCCe@                @((((((6@   \n"
		"          #ee7O66666S####R   CCCCC CCCCC CCCG@               (6(((((((6@  \n"
		"  @(66666@ eeee@########@    7CCCCCCCCCCCCCC6K              @66((((((%66~ \n"
		" %((6666##@eeeeee@####@      R7CC         CCCe      /@@@7   @666((((666#O \n"
		"@((((666###@eeeee            @(CCCCCCCCCCCCCCe    @(((((66@  ##O66666O#@  \n"
		"(6666666###ReeeeC@           #(CCCCCCCCCCCCC6e   @6(((((%6#@  R#######@   \n"
		"@666666####@  ~eeC@          O7CCCCCCCCCCCCCee   666(((66###  @e@@R@O     \n"
		" O6666####R     7eeCC@       @CCCCCCCCCCCCCCeR   R666666S###eeee  @%(O@   \n"
		"  @S#####@        KeeCCCS@##@RCCCCCCCCCCCCCCe@    66666####Reeee%((((666@ \n"
		"                    @eeee6CCCCCCCCCCCCCCCCCeeS7    @#####@eeeee(66((6666#O\n"
		"                       OeeeeCCCCCCCCCCCCCCCeeeCC@      @Oeee@#@66666666##@\n"
		"                          Re7CCCC@KCCCCCCCeeeeeCCCCCCCCCOR7    66666666##@\n"
		"                           @CCCCC(@CCCCCCGe@eeeeeeeeeee@       @##S666### \n"
		"                          OCCCCCR(6CCCCCCeeRe@@O~O~             /@######  \n"
		"                          CCCCCC6KCCCCCCeeK                               \n"
		"                         @C(66CCCCCCCKCCee/                               \n"
		"                        @CC6(CCCCCCCSRCee@                                \n"
		"                        CCS(RCCCCCCO(66ee                                 \n"
		"                       @CC@@CCCCCCC6CCee@                                 \n"
		"                      #CCCCCCCCCCCCCCCee                                  \n"
		"                      CCCCCCCCCCR@CCCee@                                  \n"
		"                     ~CCCCCCCCCS(@CCCeee                                  \n"
		"                     RCCCCCCCCS((CCCGee                                   \n"
		"                    ~CCCCCCCCCS(GCCCee@                                   \n"
		"                    @CCK(CCCCC6GCCCCee@                                   \n"
		"                    @CC@(@CCCC@CCCCCeee@                                  \n"
		"                  @C6CCG(@CCCCCCCCCCeeee~                                 \n"
		"                  CCKCC@6@CCCCCCCKCCCeee@                                 \n"
		"                  CO@CCe6CCCCCCCCCCCCCee@                                 \n"
		"                 /Ce@CCCCCCCCCCCCSeCC6eS@                                 \n"
		"                 CCCe@CCCCCCCCCCCKe@eeee/                                 \n"
		"                @CeeeO/RCCCCCCOeeeeeKeeee@                                \n"
		"                7Oee~     @KeeeeeR@  @eeeee@@OK@O                         \n"
		"             @@eeeeeK                   @eeeCCCCCCC@                      \n"
		"          @CCCCeeeeeee                     @CCCCCCCC@                     \n"
		"        OCCCCCCCCCee@                        CCCCCCCC6                    \n"
		"          ~#@@@#~                             @CCCCCee#                   \n"
		"                                                 @Ree@                    \n";

	
	if (!this->get_signed())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->get_grad_to_execute())
		throw (AForm::GradeTooLowException());
	else
	{
		file.open((this->get_target() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		if (file.is_open())
		{
			std::cout << std::setw(25) << "[ShrubberyCreationForm] " << this->get_target() << "_shrubbery " << "file create!! " << std::endl;
			file << tree << std::endl;
		}
		else
			std::cout << std::setw(25) << "[ShrubberyCreationForm] " << this->get_target() << "_shrubbery " << "Coulnd't open the output file" << std::endl;
	}
}
