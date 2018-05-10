ll Set( ll num, ll pos ) {
	return num | ( 1LL << pos );
}

ll Clear( ll num, ll pos ) {
	return num & ~( 1LL << pos );
}

ll Toggle( ll num, ll pos ) {
	return num ^ ( 1LL << pos );
}

bool Check( ll num, ll pos ) {
	return (bool) ( num & ( 1LL << pos ) );
}
