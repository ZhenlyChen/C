#include  <stdio.h>
#include  <math.h>
int low, col;

int gcd(int a, int b){
    int temp;
    
    while(b){    
        //��ȡ���Լ�� 
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//���㲢������� 
int matrix(int mat[][1000]){
	int temp = 0, intlow = mat[0][0], tp_mat[col];
	
    while(intlow == 0){
    	temp++;
    	intlow = mat[temp][0];
	} 
	//printf("%d", temp);
	// �����е�λ�ã���֤��һ�п�ͷ��Ϊ�� 
	
	if (temp != 0){
		for (int i = 0;i < col;i++){
			tp_mat[i] = mat[temp][i];
			mat[temp][i] = mat[0][i];
			mat[0][i] = tp_mat[i];
		} 
	//��֤��һ����ԪΪ���� 
	
		if (mat[0][0] < 0){
			for (int i = 0;i < col;i++)mat[0][i] = 0-mat[0][i];
		}
		
	}
	
	//���� 
	for (int i = 0;i < low;i++){   
	
		if(mat[i][0] != 0 && i>0){
			//����С������ 
			int tpn_a, tpn_b, tpn_a1, tpn_b1;
			
			tpn_a = abs(mat[i][0]);
			tpn_b = abs(mat[0][0]);
			tpn_a1 = tpn_a;
        	tpn_b1 = tpn_b;
        	
			while(tpn_a !=  tpn_b){
				
				if(tpn_a > tpn_b)
					tpn_a -=  tpn_b;
				else
					tpn_b -=  tpn_a;
			}
			tpn_a = tpn_b1/tpn_a;
			tpn_b = tpn_a1/tpn_b;
			
			if (mat[i][0]>0) 
				for (int j = 0;j < col;j++) 
					mat[i][j] = 0-mat[i][j];
				for ( int m = 0;m < col;m++ )
					mat[i][m] = ( mat[0][m] * tpn_b)  + ( mat[i][m] * tpn_a );	
		}
		int temp1 = mat[i][0];
		
		for(int f = 1;f < col;f++){
			temp1 = gcd(temp1, mat[i][f]);
		}
		
		if (temp1 != 0){
			for ( int q = 0;q < col;q++ ){
				mat[i][q] = mat[i][q]/temp1;
			}
		}
		
	}
	//��� 
	for (int i = 0;i < low;i++){
		//printf("0 ");
		
		for (int j = 0;j < col;j++)
			printf("%d ", mat[i][j]);
		printf("\n");
		
		//if (i < low-1) printf("\n0 ");
	}
	return 0;
 } 
	 	


int main(){
	//������󴢴�ռ� 
	int fuck, tmpmat[low][1000], is_quit;
	
	printf("\nPlease input low:");
	scanf("%d", &low);
	int mat2[low - 1][1000], mat[low][1000];
	printf("\nPlease input column:");
	scanf("%d", &col);
	//���� 
	for (int i = 0; i < low;i++){
		for (int j = 0; j < col;j++){
			printf("\nPlease input low:%d column:%d :", i + 1, j + 1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	matrix(mat);
	printf("\nGO ON?(Y = 0/N = 1) :");
	scanf("%d", &fuck);
	
	if (fuck == 0){
		
		for (int i = 0;i < low-1;i++)
			for (int j = 0;j < col-1;j++)
				mat2[i][j] = mat[i+1][j+1];
				
		low -= 1;
		col -= 1;
         //printf("\nResult:\n");
		//for (int i    =    0;i < low+2;i++)printf("%d ",mat[0][i]);
		//printf("\n");
	    matrix(mat2);
	}
	
    scanf("%d", &is_quit);
	return 0;
}

