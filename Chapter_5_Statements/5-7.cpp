if (ival1 != ival2) {
    ival1 = ival2;
}
else {
    ival1 = ival2 = 0;
}

if (ival < minval) {
    minval = ival;
    occurs = 1;
}

if (int ival == get_value()) {
    cout << "ival = " << ival << endl;
}
if (!ival) {
    cout << "ival = 0\n";
}

if (ival == 0) {
    ival = get_value();
}