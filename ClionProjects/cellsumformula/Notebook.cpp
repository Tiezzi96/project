//
// Created by bernardo on 15/10/17.
//

#include "Notebook.h"
#include "ListException.h"

Notebook::Notebook(const wxString &title) :
        wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1260, 500)) {
    wxNotebook *nb = new wxNotebook(this, -1, wxPoint(-1, -1), wxSize(-1, -1), wxNB_BOTTOM);

    wxMenuBar *menu_bar = new wxMenuBar;
    wxMenu *file = new wxMenu;

    file->Append(wxID_EXIT, wxT("Quit"), wxT(""));
    menu_bar->Append(file, wxT("&File"));
    SetMenuBar(menu_bar);
    wxBoxSizer *h_box2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *v_box = new wxBoxSizer(wxVERTICAL);

    wxButton *New = new wxButton(this, 1, wxT("New"));
    wxButton *Delete = new wxButton(this, 2, wxT("Delete"));
    wxButton *sum = new wxButton(this, 3, wxT("Sum"));
    wxButton *max = new wxButton(this, 4, wxT("Max"));
    wxButton *min = new wxButton(this, 5, wxT("Min"));
    wxButton *mean = new wxButton(this, 6, wxT("Mean"));
    wxButton *change = new wxButton(this, 7, wxT("Change"));
    wxButton *cellscontrol= new wxButton(this, 8, wxT("CellsControl"));
    ctrl = new wxTextCtrl(this,9,wxT(""));
    ctrl1 = new wxTextCtrl(this, 10,wxT(""));
    ctrl2 = new wxTextCtrl(this, 11, wxT(""));

    h_box2->Add(New);
    h_box2->Add(ctrl1);
    h_box2->Add(Delete);
    h_box2->Add(ctrl2);
    h_box2->Add(sum);
    h_box2->Add(max);
    h_box2->Add(min);
    h_box2->Add(mean);
    h_box2->Add(change);
    h_box2->Add(cellscontrol);
    h_box2->Add(ctrl);
    v_box->Add(h_box2);

    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::newCell));
    New->SetFocus();
    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::deleteCell));
    Delete->SetFocus();
    Connect(3, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::sumFormula));
    sum->SetFocus();
    Connect(4, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::maxFormula));
    max->SetFocus();
    Connect(5, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::minFormula));
    min->SetFocus();
    Connect(6, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::meanFormula));
    mean->SetFocus();
    Connect(7, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::change_value));
    change->SetFocus();
    Connect(8, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Notebook::cellscontrol));
    cellscontrol->SetFocus();



    Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Notebook::OnQuit));




    MyGrid *my_grid1 = new MyGrid(nb);
    MyGrid *my_grid2 = new MyGrid(nb);
    MyGrid *my_grid3 = new MyGrid(nb);

    nb->AddPage(my_grid1, wxT("Sheet1"));
    nb->AddPage(my_grid2, wxT("Sheet2"));
    nb->AddPage(my_grid3, wxT("Sheet3"));
    grid.push_back(my_grid1);
    grid.push_back(my_grid2);
    grid.push_back(my_grid3);


    v_box->Add(nb);
    SetSizer(v_box);


    CreateStatusBar();
    Center();


}

void Notebook::OnQuit(wxCommandEvent & WXUNUSED(event)) {
    Close(true);

}

void Notebook::OnChangeValue(wxCommandEvent &WXUNUSED(event)) {
    for (auto itr = begin(grid); itr != end(grid); itr++) {
        (*itr)->change_value();
    }

}

float Notebook::newcell() {
    float r=-1;
    if(strcmp(ctrl1->GetValue(),"")){
        wxString s = ctrl1->GetValue();
        double value;
        s.ToDouble(&value);
        r=(float) value;
        ctrl1->SetValue(wxT(""));
    } else{
        r =(static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100));
    }

    wxString my_string = wxString::Format(wxT("%f"), r);
    double value;
    my_string.ToDouble(&value);

    float f = (float) value;
    float troncato=((float)((int)(f*100.0f)))/100.0f;

    Cell * cell= new Cell(f);

    cells.push_back(cell);
    return cell->getValue();

}

bool Notebook::isFull() {
    auto itr=grid.begin();
    for(int i=0; i<14;i++){
        for (int j = 0; j <10 ; j++) {
            if((*itr)->GetCellValue(i,j)=="Null"){
                return false;
            }
        }
    }
    return true;
}

bool Notebook::isEmpty() {
    if(cells.size()==0){
        return true;
    }
    return false;
}

void Notebook::newCell(wxCommandEvent &WXUNUSED(event)) throw(NumberCellsOutOfRangeException) {
    if(isFull()){
        throw NumberCellsOutOfRangeException("Errore impossibile aggiungere Cella: overflow per numero di celle");
    }
    float r = newcell();
    wxString my_string = wxString::Format(wxT("%f"), r);
    int i = rand() % 14;
    int j = rand() % 10;
    for (auto itr2 = begin(grid); itr2 != end(grid); itr2++) {
        wxString s = (*itr2)->GetCellValue(i,j);
        while (s != "Null"){
            i = rand() % 14;
            j = rand() % 10;
            s = (*itr2)->GetCellValue(i,j);
        }
        (*itr2)->SetCellValue(i, j, my_string);
    }


}

void Notebook::deleteCell(wxCommandEvent &WXUNUSED(event)) throw(NumberCellsUnderflowException) {
    if (isEmpty()) {
        throw NumberCellsUnderflowException("Errore impossibile rimuovere cella: lista vuota");
    }
    std::cout << cells.size() << std::endl;
    int d = -1;
    if (strcmp(ctrl2->GetValue(), "")) {
        wxString s = ctrl2->GetValue();
        double value;
        s.ToDouble(&value);
        d = (int) value;
        ctrl2->SetValue(wxT(""));

    } else {
        int size = (int) cells.size();
        d = rand() % size;
    }
    auto itr = begin(cells);
    int k = 0;
    while (k < d) {
        itr++;
        k++;
    }
    float r = (*itr)->getValue();
    std::cout << (*itr)->getValue() << std::endl;
    Sum.removeCell(*itr);
    Max.removeCell(*itr);
    Min.removeCell(*itr);
    Mean.removeCell(*itr);
    cells.remove(*itr);
    int i = rand() % 14;
    int j = rand() % 10;
    wxString my_string = wxString::Format(wxT("%f"), r);
    for (auto itr2 = begin(grid); itr2 != end(grid); itr2++) {
        while ((*itr2)->GetCellValue(i, j) != my_string) {
            i = rand() % 14;
            j = rand() % 10;
        }
        (*itr2)->SetCellValue(i, j, wxT("Null"));
    }
}
void Notebook::sumFormula(wxCommandEvent &WXUNUSED(event)) {
    float result=Sum.calc();
    wxString my_string = wxString::Format(wxT("%f"), result);
    for(auto itr = begin(grid); itr != end(grid); itr++){
        (*itr)->SetCellValue(1,10,my_string);
    }

}


void Notebook::maxFormula(wxCommandEvent &WXUNUSED(event)) {
    float result=Max.calc();
    wxString my_string = wxString::Format(wxT("%f"), result);
    for(auto itr = begin(grid); itr != end(grid); itr++){
        (*itr)->SetCellValue(1,11,my_string);
    }

}


void Notebook::minFormula(wxCommandEvent &WXUNUSED(event)) {
    float result=Min.calc();
    wxString my_string = wxString::Format(wxT("%f"), result);
    for(auto itr = begin(grid); itr != end(grid); itr++){
        (*itr)->SetCellValue(1,12,my_string);
    }

}

void Notebook::meanFormula(wxCommandEvent &WXUNUSED(event)) {
    float result=Mean.calc();
    wxString my_string = wxString::Format(wxT("%f"), result);
    for(auto itr = begin(grid); itr != end(grid); itr++){
        (*itr)->SetCellValue(1,13,my_string);
    }

}

void Notebook::cellscontrol(wxCommandEvent& WXUNUSED(event)){
    wxString s=ctrl->GetValue();
    if(!strcmp(s,""))
        return;
    double value;
    s.ToDouble(&value);
    int r = (int) value;
    if(r>(int) cells.size())
        return;
    int sumsize=(int) Sum.cellsSize();
    auto itr =begin(cells);
    int j =0;
    while (j<sumsize){
        itr++;
        j++;
    }
    int k = 0;
    if (r<(int) Sum.cellsSize()) {
        int m = 0;
        int diff = ((int) Sum.cellsSize()-r);
        std::list<Cell*> sumcell = Sum.getcell();
        auto itr2 = end(sumcell);
        itr2--;
        while(m<diff){
            (*itr2)->removeObserver(&Sum);
            (*itr2)->removeObserver(&Max);
            (*itr2)->removeObserver(&Min);
            (*itr2)->removeObserver(&Mean);
            Sum.pop_back();
            Min.pop_back();
            Max.pop_back();
            Mean.pop_back();
            itr2--;
            m++;
        }
        return;
    }
    else
        r= r-((int) Sum.cellsSize());
    while (k < r){
        Sum.addCell(*itr);
        (*itr)->addObserver(&Sum);
        Min.addCell(*itr);
        (*itr)->addObserver(&Min);
        Max.addCell(*itr);
        (*itr)->addObserver(&Max);
        Mean.addCell(*itr);
        (*itr)->addObserver(&Mean);
        k++;
        itr++;

    }
    std::list<Cell*> c=Sum.getcell();


}


void Notebook::change_value(wxCommandEvent & WXUNUSED(event)) {
    auto itr = begin(cells);
    int size = (int) cells.size();
    float value = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/100));

    int r = rand() % size;
    int k = 0;
    while (k < r) {
        itr++;
        k++;
    }
    int x =-1;
    int y=-1;
    wxString s1 = wxString::Format(wxT("%f"), (*itr)->getValue());
    for (auto itr2 = begin(grid); itr2 != end(grid); itr2++) {
        for(int i =0; i<14; i++){
            for(int j =0; j<10; j++){
                wxString s = (*itr2)->GetCellValue(i, j);
                if (!wxStrcmp(s,s1)){
                    x =i;
                    y =j;
                }
            }
        }
        if(x==-1 && y==-1)
            return;
        (*itr)->setValue(value);
        wxString s2 = wxString::Format(wxT("%f"), (*itr)->getValue());
        (*itr2)->SetCellValue(x, y, s2);
    }

}








