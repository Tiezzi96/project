//
// Created by bernardo on 16/10/17.
//

#include "MyGrid.h"

MyGrid::MyGrid(wxNotebook *parent):wxGrid(parent, wxID_ANY, wxDefaultPosition, wxSize(700, 350))
{

    CreateGrid(14, 14);
    SetRowLabelSize(50);
    SetColLabelSize(25);
    SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
    SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

    for(int i=0; i<14; i++)
    {
        this->SetRowSize(i,25);
    }

    for(int i=0; i<10; i++)
    {
        this->SetColLabelValue(i,wxString::Format(wxT("%i"),i+1));

    }
    this->SetColLabelValue(10, wxT("Sum"));
    this->SetColLabelValue(11, wxT("Max"));
    this->SetColLabelValue(12, wxT("Min"));
    this->SetColLabelValue(13, wxT("Mean"));
    for(int i=0;i < 10; i++){
        for(int j=0; j< 10; j++){
            this->SetCellValue(i,j, wxT("Null"));

        }

    }


    //this->change_value();

}



void MyGrid::change_value(){
    for(int i=0;i < 10; i++){
        for(int j=0; j< 10; j++){
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/10);
            wxString my_string = wxString::Format(wxT("%f"),r);
            this->SetCellValue(i,j, my_string);

        }

    }
}
