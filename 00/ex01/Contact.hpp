/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:06:14 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:41:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact();
        void    setFirstName(std::string str);
        std::string getFirstName(void);
        void    setLastName(std::string str);
        std::string getLastName(void);
        void    setNickname(std::string str);
        std::string getNickname(void);
        void    setPhoneNumber(std::string str);
        std::string getPhoneNumber(void);
        void    setDarkestSecret(std::string str);
        std::string getDarkestSecret(void);
        void    printContact(void);
        void    printContactFull(void);
        void    setIndex(int ind);
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        int index;
        std::string modifyString(std::string str);
};

#endif
