//
//  Respring.swift
//  Respring
//
//  Created by Somica on 09/06/2021.
//

import UIKit

final class Respring {
    
    public class func respring(_ window: UIWindow, animation: Bool = true) {
        // Break early if you don't want any closing animation, this is all you need to kill Springboard
        if !animation {
            while true {
                window.snapshotView(afterScreenUpdates: false)
            }
            // Control flow will never reach here because the block never exits
        }
        
        // Create our animation object to make the window invisble and make it smaller to give it the closing effect
        let animator = UIViewPropertyAnimator(duration: 0.5, dampingRatio: 1) {
            window.alpha = 0
            window.transform = .init(scaleX: 0.9, y: 0.9)
        }
        // When the animation has finished, fire the dumb respring code
        animator.addCompletion { _ in
            while true {
                window.snapshotView(afterScreenUpdates: false)
            }
        }
        // Fire the animation
        animator.startAnimation()
    }
    
}
