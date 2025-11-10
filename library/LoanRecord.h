class LoanRecord {
    unsigned int id;
    string isbn;
    time_t issue_data, due_data;
    bool returned = false;
};