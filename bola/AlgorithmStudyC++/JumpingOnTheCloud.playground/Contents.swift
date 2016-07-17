//: Playground - noun: a place where people can play
/*
 참고 ! 플레이 그라운드에서는 입력을 받을 수 없다!
 
 */


import Cocoa

var str = "Hello, playground"

func jumpingOnTheCloud() {

    var energy = 100
    var n = 0 //구름 수
    var k = 0 //점프 거리
    var clouds : Array<Bool>//구름들
    
    //입력 받는 부분
    if let nAndKString = readLine() {
        
        let nAndK = nAndKString.componentsSeparatedByString("  ")
        n = Int(nAndK[0])!
        k = Int(nAndK[1])!
        clouds = Array<Bool>();
        
        //구름 입력
        if let cloudInputString = readLine() {
            
            let cloudInput = cloudInputString.componentsSeparatedByString(" ")
            for cloud in cloudInput {
                if(cloud == "1") {
                    clouds.append(true)
                }
                else {
                    clouds.append(false)
                }
            }
        }
        else {
            return
        }
        
        //본 로직
        var position = 0 //현재 위치 초기화
        
        repeat {
            //점프한다. 에너지 1을 쓴다
            energy = energy - 1
            position = (position + k) % n //항상 0 ~ n-1의 값만 나오니까 검사 해 줄 필요없음
            //번개 구름에 착륙 시 에너지 2가 더 감소한다
            if(clouds[position] == true) {
                energy = energy - 2
            }
            
            
        }while(position != 0); //0에 다시 도착시 종료한다
        
        //결과(남은 에너지의 양)를 출력한다
        print(energy)
            
        
        
        
    }
    

}


jumpingOnTheCloud()