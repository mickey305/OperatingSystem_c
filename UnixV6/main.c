// Unix v6
estabur(nt, nd, ns, sep){
	register a, *ap, *dp;

	/* 妥当性を確かめる */
	if(sep){
		if(cputype == 40){
			goto err;
		}
		if(nseg(nt) > 8 || nseg(nd)+nseg(ns) > 8){
			goto err;
		}

	}else{
		if(nseg(nt)+nseg(nd)+nseg(ns) > 8){
			goto err;
		}
	}
	if(nt+nd+ns+USIZE > maxmen){
		goto err;
	}

	/* テスト領域の割り当て */
	a = 0;
	ap = &u.u_uisa[0];
	dp = &u.u_uisd[0];
	while(nt >= 128){
		*dp++ = (127<<8) | RO;
		*ap++ = a;
		a =+ 128;
		nt =- 128;

	}
	if(nt){
		*dp++ = ((nt - 1)<<8) | RO;
		*ap++ = a;

	}
	if(sep){
		while(ap < &u.u_uisa[8]){
			*ap++ = 0;
			*dp++ = 0;

		}
	}

	/* データ領域の割り当て */
	a = USIZE;
	while(nd >= 128){
		*dp++ = (127<<8) | RW;
		*ap++ = a;
		a =+ 128;
		nd =- 128;

	}
	if(nd){
		
	}