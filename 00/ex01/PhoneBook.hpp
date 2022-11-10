/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:49:55 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:41:07 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <limits>

#define COUNT 8

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    void addContact(void);
    void searchBook(void);
    void printall(void);
private:
    int count;
    int index;
    Contact contacts[COUNT];
    Contact tmp;
    bool    addFirstName(void);
    bool    addLastName(void);
    bool    addNickname(void);
    bool    addPhonenumber(void);
    bool    addDarkestSecret(void);
    void printone(int index);
};

#endif
