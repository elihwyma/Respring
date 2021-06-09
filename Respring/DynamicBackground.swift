//
//  DynamicBackground.swift
//  Respring
//
//  Created by Somica on 09/06/2021.
//

import UIKit

class DynamicColourView: UIView {
    
    public var enableRandomColour = true
    var gradientLayer: CAGradientLayer!
    var colours = [CGColor]()
    
    private func randomColour() -> UIColor {
        let red = CGFloat((arc4random() % 256)) / 255.0
        let green = CGFloat((arc4random() % 256)) / 255.0
        let blue = CGFloat((arc4random() % 256)) / 255.0
        let alpha = CGFloat(1.0)
        
        return UIColor(red: red, green: green, blue: blue, alpha: alpha)
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    required override init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        if self.gradientLayer != nil {
            self.gradientLayer.frame = self.bounds
        }
    }
    
    public func setup() {
        #if os(iOS)
        if !UIAccessibility.isReduceTransparencyEnabled {
            let blurEffect = UIBlurEffect(style: .extraLight)
            let blurEffectView = UIVisualEffectView(effect: blurEffect)

            blurEffectView.frame = self.bounds
            blurEffectView.autoresizingMask = [.flexibleWidth, .flexibleHeight]

            self.addSubview(blurEffectView)
        }
        #endif
        self.gradientLayer = CAGradientLayer(start: .topLeft, end: .bottomRight, colors: [randomColour().cgColor, randomColour().cgColor], type: .radial)
        
        self.gradientLayer.frame = self.bounds
        self.layer.addSublayer(self.gradientLayer)
        
        self.randomColours()
    }

    private func randomColours() {
        var toColours = [CGColor]()
        
        if self.enableRandomColour || colours.count == 0 {
            toColours = [randomColour().cgColor, randomColour().cgColor, randomColour().cgColor]
        } else {
            toColours = self.colours
        }
        
        let colourAnimation = CABasicAnimation(keyPath: "colors")
        colourAnimation.fromValue = self.gradientLayer.colors
        colourAnimation.toValue = toColours
        colourAnimation.duration = 3.0
        colourAnimation.isRemovedOnCompletion = true
        colourAnimation.delegate = self
     
        self.gradientLayer.colors = toColours
        self.gradientLayer.add(colourAnimation, forKey: nil)
    }
}

extension DynamicColourView: CAAnimationDelegate {
    func animationDidStop(_ anim: CAAnimation, finished flag: Bool) {
        if let animation = anim as? CABasicAnimation {
            switch animation.keyPath {
                case "colors" : self.randomColours()
                default : return
            }
        }
    }
}

extension CAGradientLayer {
    
    enum Point {
        case topLeft
        case centerLeft
        case bottomLeft
        case topCenter
        case center
        case bottomCenter
        case topRight
        case centerRight
        case bottomRight
        var point: CGPoint {
            switch self {
            case .topLeft:
                return CGPoint(x: 0, y: 0)
            case .centerLeft:
                return CGPoint(x: 0, y: 0.5)
            case .bottomLeft:
                return CGPoint(x: 0, y: 1.0)
            case .topCenter:
                return CGPoint(x: 0.5, y: 0)
            case .center:
                return CGPoint(x: 0.5, y: 0.5)
            case .bottomCenter:
                return CGPoint(x: 0.5, y: 1.0)
            case .topRight:
                return CGPoint(x: 1.0, y: 0.0)
            case .centerRight:
                return CGPoint(x: 1.0, y: 0.5)
            case .bottomRight:
                return CGPoint(x: 1.0, y: 1.0)
            }
        }
    }
    
    convenience init(start: Point, end: Point, colors: [CGColor], type: CAGradientLayerType) {
        self.init()
        self.startPoint = start.point
        self.endPoint = end.point
        self.colors = colors
        self.locations = (0..<colors.count).map(NSNumber.init)
        self.type = type
    }
}
